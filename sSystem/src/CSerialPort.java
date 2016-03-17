package src;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.microedition.io.CommConnection;
import javax.microedition.io.Connector;

public class CSerialPort {
		CommConnection	commConn;
		InputStream   	inStream;
		OutputStream  	outStream;

		public CSerialPort()
		{
	        try 
	        {
				String strCOM = "comm:com0;" +
				"baudrate=115200;" +
				"bitsperchar=8;" +
				"stopbits=1;" +
				"parity=none;" +
				"blocking=off;" + 
				"autocts=on;" +
				"autorts=on";
				commConn = (CommConnection)Connector.open(strCOM);
				inStream  = commConn.openInputStream();
				outStream = commConn.openOutputStream();
			} 
	        catch (IOException e) 
	        {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		/**
		 * Вывод информации в СОМ-порт
		 * @param s - String
		 */
		public void serialOut(String s)
		{
			serialOut(s.getBytes());
			//Sysstem.out.println(s);
		}
		/**
		 * Вывод информации в СОМ-порт
		 * @param b - byte[] array
		 */
		public void serialOut(byte[] b)
		{
			try
			{
				outStream.write(b);
			}
			catch(IOException e)
			{
				System.out.println(e);
			}
		}

		/**
		 * Вывод отладочной информации в СОМ-порт
		 * @param b - byte[] array
		 */
		public void serialOut(char c)
		{
			try
			{
				outStream.write(c);
			}
			catch(IOException e)
			{
				System.out.println(e);
			}
		}
		
		public int hasData()
		{
			int n = 0;
			try 
			{
				n = inStream.available();
			} 
			catch (IOException e) 
			{
			}
			
			return n;
		}
		
		int readByte()
		{
			int NextByte = 0;
			try {
				NextByte = inStream.read();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return NextByte;
		}
}
