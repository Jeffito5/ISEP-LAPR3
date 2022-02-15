package lapr.project.controller;

import lapr.project.network.FreightNetwork;
import lapr.project.network.VertexLocation;
import lapr.project.utils.Pair;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;

import static org.testng.Assert.assertEquals;

class MostEfficiencyCircuitControllerTest {
    CreateFreightNetworkController fnc = new CreateFreightNetworkController();
    FreightNetwork freightNetworkP = App.getInstance().getCompany().getFreightNetwork();
    MostEfficiencyCircuitController controller = new MostEfficiencyCircuitController();

    @Test
    void getMostEfficiencyCircuitInFreightNetwork() {
//        fnc.createFreightNetwork(1);
//        System.out.println();
//        VertexLocation vertexLocation = freightNetworkP.getLocationByName("Lisbon");
//        Pair<LinkedList<VertexLocation>,Double> circuit= freightNetworkP.getMostEfficiencyCircuit(vertexLocation);
//        assertEquals(circuit.getFirst().getFirst(),vertexLocation);
//        assertEquals(circuit.getFirst().getLast(),vertexLocation);
    }

    @Test
    void getMostEfficiencyCircuitInController() {
//        fnc.createFreightNetwork(1);
//        System.out.println();
//        VertexLocation vertexLocation = freightNetworkP.getLocationByName("Lisbon");
//
//        Exception exception1= Assertions.assertThrows(IllegalArgumentException.class, ()->controller.getMostEfficiencyCircuit("Porto",1));
//        String message1="The system hasn't no city registered with name Porto";
//        Exception exception2= Assertions.assertThrows(IllegalArgumentException.class, ()->controller.getMostEfficiencyCircuit("Porto",0));
//        String message2="The system hasn't no port registered with name Porto";
//        Exception exception3= Assertions.assertThrows(IllegalArgumentException.class, ()->controller.getMostEfficiencyCircuit("Setubal",2));
//        String message3="Wrong option selection";
//
//        assertEquals(exception1.getMessage(),message1);
//        assertEquals(exception2.getMessage(),message2);
//        assertEquals(exception3.getMessage(),message3);
//
//        Pair<LinkedList<VertexLocation>,Double> circuit=controller.getMostEfficiencyCircuit("Lisbon",1);
//        Pair<LinkedList<VertexLocation>,Double> circuit2=freightNetworkP.getMostEfficiencyCircuit(vertexLocation);
//        assertEquals(circuit.getFirst().getFirst(),vertexLocation);
//        assertEquals(circuit.getFirst().getLast(),vertexLocation);
//        assertEquals(circuit2.getFirst().getFirst(),vertexLocation);
//        assertEquals(circuit2.getFirst().getLast(),vertexLocation);

    }
}