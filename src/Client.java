
import arduino.Arduino;
import java.util.Scanner;
import java.io.*;



public class Client {

    public static void main(String[] args) throws InterruptedException{

        try (RW rW = new RW("192.168.0.110", 9000)) {
            rW.writeLine("userKey");
        Arduino arduino = new Arduino("COM3", 19200);
        arduino.openConnection();
        Thread.sleep(2000);
        while (true) {
            try {
                String Id = arduino.serialRead();
                if (!Id.equals("") && !Id.equals(null) && !Id.contains("+DISC:SUCCESS\n" + "OK")) {
                    String id = "";
                    char[] b = new char[Id.length() - 1];
                    Id.getChars(0, Id.length() - 1, b, 0);
                    for (int a = 0; a < b.length; a++) {
                        id = id + b[a];
                    }

                    rW.write(Integer.parseInt(id));
                    String resp = rW.readLine();
                    if (resp.equals("On")) {
                        arduino.serialWrite('1');
                    } else if (resp.equals("Off")) {
                        arduino.serialWrite('0');
                    }
                }
            } catch (IOError e) {
                System.out.println("kekus");
            }
        }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
