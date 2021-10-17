public class Mainthread extends Thread {           //here thread class is provided to create and perform operations on thread.Mainthread extends thread class.
  
  public static void main(String[] args) {         //public-access modifier,static method,return type, main-startup of program,command line arguments.
    
    Mainthread thread = new Mainthread();          //thread is created or its lifecycle started
    
    thread.start();                                //start()method of thread class is used to start a newly created thread.
    
    System.out.println("This code is outside of the thread");
  }
  public void run() {                              //this fuction is used to perform action for a thread
    
    System.out.println("This code is running in a thread");
  }
}
