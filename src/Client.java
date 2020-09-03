
import arduino.Arduino;
import java.util.Scanner;
import java.io.*;



public class Client {

    public static void main(String[] args) throws InterruptedException{

        Arduino arduino = new Arduino("COM3", 9600);
        arduino.openConnection();
        Thread.sleep(2000);
        //waiting for bluetooth connection
            try (RW rW = new RW("192.168.0.110", 9000)) {
                rW.writeLine("userKey");
                int Id = 251; //get id via bluetooth
                rW.write(Id);
                String resp = rW.readLine();


                if (resp.equals("On")) {
                    arduino.serialWrite('1');
                } else {
                    arduino.serialWrite('0');
                }



            } catch (IOException e) {
                e.printStackTrace();
            }


    }
}
