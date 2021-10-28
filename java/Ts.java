import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Ts {
    public static void main(String[] args)throws Exception{
        PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
        Date date = new Date();
        out.printf("date.getTime() = %d, calendar.getTimeInMillis() = %d\n", date.getTime(), Calendar.getInstance().getTimeInMillis());
        Thread.sleep(4444);
        out.printf("date.getTime() = %d, calendar.getTimeInMillis() = %d\n", date.getTime(), Calendar.getInstance().getTimeInMillis());
        out.close();
    }
}
