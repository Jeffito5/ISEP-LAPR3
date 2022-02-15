package lapr.project.graph.matrix;

import lapr.project.graph.BasicGraph;
import lapr.project.graph.Edge;
import lapr.project.network.VertexLocation;

import java.util.*;

/**
 * @author DEI-ESINF
 */
public class AdjacencyMatrixGraph<V, E> implements BasicGraph<V, E>, Cloneable {

    public static final int INITIAL_CAPACITY = 10;
    public static final float RESIZE_FACTOR = 1.5F;

    int numVertices;
    int numEdges;
    ArrayList<V> vertices;
    E[][] edgeMatrix;


    /**
     * Constructs an empty graph.
     */
    public AdjacencyMatrixGraph() {
        this(INITIAL_CAPACITY);
    }

    /**
     * Constructs a graph with an initial capacity.
     */
    @SuppressWarnings("unchecked")
    public AdjacencyMatrixGraph(int initialSize) {
        vertices = new ArrayList<>(initialSize);

        edgeMatrix = (E[][]) new Object[initialSize][initialSize];
    }

    public AdjacencyMatrixGraph(ArrayList<V> vs, E[][] m) {
        this(vs.size());
        numVertices = vs.size();
        vertices = new ArrayList<>(vs);
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                if (j != i && m[i][j] != null)
                    insertEdge(vertices.get(i), vertices.get(j), m[i][j]);
    }

    /**
     * Returns the edge reference associated with edgeMatrix x,y position
     * used as workaround to work with edgeMatrix from the EdgeAsDoubleGraphAlgorithm Class
     * as Java generic types are not available at runtime
     *
     * @param x,y the position in the matrix
     * @return edge at position (x,y)
     */
    public E privateGet(int x, int y) {
        return edgeMatrix[x][y];
    }

    /**
     * Set the edge reference associated with edgeMatrix x,y position
     * used as workaround to work with edgeMatrix from the EdgeAsDoubleGraphAlgorithm Class
     * as Java generic types are not available at runtime
     *
     * @param x,y the position in the matrix
     * @param e   the new reference
     */
    void privateSet(int x, int y, E e) {
        edgeMatrix[x][y] = e;
    }

    /**
     * Returns the index associated with a vertex
     *
     * @param vertex
     * @return vertex index, -1 if vertex does not exist in the graph
     */

    public int toIndex(V vertex) {
        return vertices.indexOf(vertex);
    }

    /**
     * Resizes the matrix when a new vertex increases the length of ArrayList
     */
    private void resizeMatrix() {
        if (edgeMatrix.length < numVertices) {
            int newSize = (int) (edgeMatrix.length * RESIZE_FACTOR);

            @SuppressWarnings("unchecked")
            E[][] temp = (E[][]) new Object[newSize][newSize];
            for (int i = 0; i < edgeMatrix.length; i++)
                temp[i] = Arrays.copyOf(edgeMatrix[i], newSize);

            edgeMatrix = temp;
        }
    }

    /**
     * Returns the number of vertices in the graph
     *
     * @return number of vertices of the graph
     */
    public int numVertices() {
        return numVertices;
    }

    /**
     * Returns the number of edges in the graph
     *
     * @return number of edges of the graph
     */
    public int numEdges() {
        return numEdges;
    }

    /**
     * Checks if a vertex exist
     *
     * @param vertex
     * @return true if exists
     */
    public boolean checkVertex(V vertex) {
        return (vertices.indexOf(vertex) != -1);
    }

    /**
     * Returns the actual vertices of the graph
     *
     * @return an iterable collection of vertices
     */
    @SuppressWarnings("unchecked")
    public Iterable<V> vertices() {
        return (Iterable<V>) vertices.clone();
    }

    /**
     * Returns the actual edges of the graph
     *
     * @return an iterable collection of all edges
     */
    public Iterable<E> edges() {
        ArrayList<E> edges = new ArrayList<>();

        // graph is undirected, so only return a single copy of edge
        // graph could actually only keep one copy of the edge but algorithms
        // would then need to consider that case.

        for (int i = 0; i < numVertices - 1; i++)
            for (int j = i + 1; j < numVertices; j++)
                if (edgeMatrix[i][j] != null)
                    edges.add(edgeMatrix[i][j]);

        return edges;
    }

    /**
     * Returns the number of edges leaving vertex, -1 if vertex doesn't exist
     * This is the same result returned by inDegree
     *
     * @param vertex
     * @return number of edges leaving vertex v,
     */
    public int outDegree(V vertex) {
        int index = toIndex(vertex);
        if (index == -1)
            return -1;

        int edgeCount = 0;
        for (int i = 0; i < numVertices; i++)
            if (edgeMatrix[index][i] != null)
                edgeCount++;

        return edgeCount;
    }

    /**
     * Returns the number of edges reaching vertex. This is the same result
     * returned by outDegree
     *
     * @param vertex
     * @return number of edges reaching vertex v
     */
    public int inDegree(V vertex) {
        return outDegree(vertex);
    }

    /**
     * Returns an iterable collection of vertices directly connected to vertex
     *
     * @param vertex
     * @return collection of vertices connected to vertex, null if vertex
     * does not exist in the graph
     */
    public Iterable<V> directConnections(V vertex) {
        int index = toIndex(vertex);
        if (index == -1)
            return null;

        ArrayList<V> directConnections = new ArrayList<>();

        for (int i = 0; i < numVertices; i++) {
            if (edgeMatrix[index][i] != null) {
                directConnections.add(vertices.get(i));
            }
        }
        return directConnections;
    }


    /**
     * Returns an iterable collection of edges for which vertex is the origin.
     * This is the same result as returned by incomingEdges.
     *
     * @param vertex
     * @return collection of edges leaving vertex, null if vertex does
     * not exist in the graph
     */
    public Iterable<E> outgoingEdges(V vertex) {
        int index = toIndex(vertex);
        if (index == -1) return null;

        ArrayList<E> outgoingEdges = new ArrayList<>();

        for (int i = 0; i < numVertices; i++) {
            if (edgeMatrix[index][i] != null) {
                outgoingEdges.add(edgeMatrix[index][i]);
            }
        }
        return outgoingEdges;
    }

    /**
     * Returns an iterable collection of edges for which vertex v is the
     * destination. This is the same result as returned by incomingEdges.
     *
     * @param vertex
     * @return collection of edges reaching vertex, null if vertex does not
     * exist in the graph
     */
    public Iterable<E> incomingEdges(V vertex) {
        return outgoingEdges(vertex);
    }

    /**
     * Returns the edge between two vertices
     *
     * @param vertexA
     * @param vertexB
     * @return the edge or null if source and dest are not adjacent or do not
     * exist in the graph.
     */
    public E getEdge(V vertexA, V vertexB) {
        int indexA = toIndex(vertexA);
        if (indexA == -1)
            return null;

        int indexB = toIndex(vertexB);
        if (indexB == -1)
            return null;

        return edgeMatrix[indexA][indexB];
    }

    @Override
    public Edge<V, E> getEdge2(V vOrig, V vDest) {
        if (!validVertex(vOrig) || !validVertex(vDest))
            return null;

        if (edgeMatrix[toIndex(vOrig)][toIndex(vDest)] == null)
            return null;

        return new Edge<>(vOrig, vDest, edgeMatrix[toIndex(vOrig)][toIndex(vDest)]);
    }

    public E getEdge(int indexA, int indexB) {
        return edgeMatrix[indexA][indexB];
    }

    /**
     * Returns the vertices of an edge, as an array of length two.
     *
     * @param edge
     * @return array of two vertices or null if edge does not exist in the
     * graph.
     */
    public V[] endVertices(E edge) {
        for (int i = 0; i < numVertices - 1; i++)
            for (int j = i + 1; j < numVertices; j++)
                if (edgeMatrix[i][j] != null)
                    if (edgeMatrix[i][j].equals(edge)) {
                        @SuppressWarnings("unchecked")
                        V[] result = (V[]) new Object[2];
                        result[0] = vertices.get(i);
                        result[1] = vertices.get(j);
                        return result;
                    }
        return null;
    }

    public Collection<V> adjVertices(V vert) {
        int index = key(vert);
        if (index == -1)
            return null;
        int numVerts = vertices.size();
        ArrayList<V> outVertices = new ArrayList<>();
        for (int i = 0; i < numVerts; i++)
            if (edgeMatrix[index][i] != null)
                outVertices.add(vertices.get(i));
        return outVertices;
    }

    @Override
    public Edge edge(V vOrig, V vAdj) {
        return null;
    }

    /**
     * Inserts a new vertex with the given element.
     * fails if vertex already exists
     *
     * @param newVertex (vertex contents)
     * @return false if vertex exists in the graph
     */
    public boolean insertVertex(V newVertex) {
        int index = toIndex(newVertex);
        if (index != -1)
            return false;

        vertices.add(newVertex);
        numVertices++;
        resizeMatrix();
        return true;
    }

    /**
     * Inserts a new edge between two vertices.
     * Package level method is for use of algorithms class
     *
     * @param indexA
     * @param indexB
     * @param newEdge
     * @return false if vertices are not in the graph or are the same vertex
     * or an edge already exists between the two.
     */
    void insertEdge(int indexA, int indexB, E newEdge) {
        if (edgeMatrix[indexA][indexB] == null) {
            edgeMatrix[indexA][indexB] = edgeMatrix[indexB][indexA] = newEdge; // undirected graph
            numEdges++;
        }
    }

    public boolean insertEdge(V vertexA, V vertexB, E newEdge) {
        if (vertexA == null || vertexB == null)
            return false;

        if (vertexA.equals(vertexB))
            return false;

        int indexA = toIndex(vertexA);
        if (indexA == -1)
            return false;

        int indexB = toIndex(vertexB);
        if (indexB == -1)
            return false;

        if (edgeMatrix[indexA][indexB] != null)
            return false;

        insertEdge(indexA, indexB, newEdge);

        return true;
    }

    /**
     * Removes a vertex and all its incoming/outgoing edges from the graph.
     *
     * @param vertex vertex
     * @return false if vertex does not exist in the graph
     */
    public boolean removeVertex(V vertex) {
        int index = toIndex(vertex);
        if (index == -1)
            return false;

        // first let's remove edges to/from the vertex

        for (int i = 0; i < numVertices; i++)
            if (edgeMatrix[index][i] != null) {
                removeEdge(index, i);
            }

        vertices.remove(index);
        numVertices--;

        // remove shifts left all vertices after the one removed
        // It is necessary to collapse the edge matrix

        //first the lines after line vertex removed
        for (int i = index; i < numVertices; i++)
            for (int j = 0; j < edgeMatrix.length; j++)
                edgeMatrix[i][j] = edgeMatrix[i + 1][j];

        for (int j = 0; j < edgeMatrix.length; j++)
            edgeMatrix[numVertices][j] = null;

        //second the columns after column vertex removed
        for (int i = index; i < numVertices; i++)
            for (int j = 0; j < edgeMatrix.length; j++)
                edgeMatrix[j][i] = edgeMatrix[j][i + 1];

        for (int j = 0; j < edgeMatrix.length; j++)
            edgeMatrix[j][numVertices] = null;

        return true;
    }

    /**
     * Removes the edge between two vertices
     * Package level method is for use of algorithms class
     *
     * @param indexA
     * @param indexB the two vertices
     * @return the edge or null if vertices are not in the graph or not
     * connected
     */
    E removeEdge(int indexA, int indexB) {
        E edge = edgeMatrix[indexA][indexB];
        edgeMatrix[indexA][indexB] = edgeMatrix[indexB][indexA] = null; // undirected graph
        numEdges--;
        return edge;
    }

    public E removeEdge(V vertexA, V vertexB) {
        int indexA = toIndex(vertexA);
        if (indexA == -1)
            return null;

        int indexB = toIndex(vertexB);
        if (indexB == -1)
            return null;

        return removeEdge(indexA, indexB);
    }

    @Override
    public boolean validVertex(V vOrig) {
        return (vertices.contains(vOrig));
    }

    @Override
    public V[] allkeyVerts() {
        List<V> v = new LinkedList<>();
        for (V ver : vertices()) {
            v.add(ver);
        }
        return (V[]) v.toArray(new Object[]{});
    }


    /**
     * Returns a string representation of the graph.
     * Matrix only represents existence of Edge
     */
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("Vertices:\n");
        for (int i = 0; i < numVertices; i++)
            sb.append(vertices.get(i) + "\n");

        sb.append("\nMatrix:\n");

        sb.append("  ");
        for (int i = 0; i < numVertices; i++) {
            sb.append(" |  " + i + " ");
        }
        sb.append("\n");

        // aligned only when vertices < 10
        for (int i = 0; i < numVertices; i++) {
            sb.append(" " + i + " ");
            for (int j = 0; j < numVertices; j++)
                if (edgeMatrix[i][j] != null)
                    sb.append("|  X  ");
                else
                    sb.append("|     ");
            sb.append("\n");
        }

        sb.append("\nEdges:\n");

        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                if (edgeMatrix[i][j] != null)
                    sb.append("From " + i + " to " + j + "-> " + edgeMatrix[i][j] + "\n");

        sb.append("\n");

        return sb.toString();
    }

    /**
     * Returns a clone of the graph (a shallow copy).
     *
     * @return the new cloned graph
     */

    @SuppressWarnings("unchecked")
    public AdjacencyMatrixGraph<V,E> clone() {
        AdjacencyMatrixGraph<V, E> newObject = new AdjacencyMatrixGraph<V, E>();

        newObject.vertices = (ArrayList<V>) vertices.clone();

        newObject.numVertices = numVertices;

        newObject.edgeMatrix = (E[][]) new Object[edgeMatrix.length][edgeMatrix.length];

        for (int i = 0; i < edgeMatrix.length; i++)
            newObject.edgeMatrix[i] = Arrays.copyOf(edgeMatrix[i], edgeMatrix.length);

        newObject.numEdges = numEdges;

        return newObject;
    }

    /**
     * Implementation of equals
     *
     * @param oth the other graph to test for equality
     * @return true if both objects represent the same graph
     */

    @Override
    public boolean equals(Object oth) {

        if (oth == null) return false;

        if (this == oth) return true;

        if (!(oth instanceof AdjacencyMatrixGraph<?, ?>))
            return false;

        AdjacencyMatrixGraph<?, ?> other = (AdjacencyMatrixGraph<?, ?>) oth;

        if (numVertices != other.numVertices || numEdges != other.numEdges) return false;

        if (!vertices.equals(other.vertices)) return false;

        if (!Arrays.deepEquals(edgeMatrix, other.edgeMatrix))
            return false;

        // fails to recognise difference between objects with different <E> type
        // when vertices are the same and both graphs have no edges

        return true;
    }

    public int key(V vert) {
        return vertices.indexOf(vert);
    }

    public int countOddVertices(){
        int countOdd=0;
        for (V v : vertices)
            if (adjVertices(v).size()%2==1)
                countOdd++;

        return countOdd;
    }

}