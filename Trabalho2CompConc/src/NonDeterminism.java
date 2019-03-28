//
// NonDeteminism.java
//
public class NonDeterminism {
    public static void main(String[] args) throws InterruptedException {
        class Container {
            public String value = "Empty";
        }
        final Container container = new Container();

        class FastThread extends Thread {
           
        	public void run() {
                container.value = "Fast";
                try {
                notify();
                }catch (Exception e) {
					// TODO: handle exception
				}
                
            }
        }

        class SlowThread extends Thread {
            public void run() {
                try {
                    Thread.sleep(50);
                    wait();
                }
                catch(Exception e) {}
                container.value = "Slow";
            }
        }
        
        FastThread fast = new FastThread();
        SlowThread slow = new SlowThread();
        fast.start(); slow.start();
        fast.join(); slow.join();
        System.out.println(container.value);
    }
}