package ru.java.task1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.InvocationTargetException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.ServletInputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.google.gson.Gson;

import ru.java.datamodel.RemoteCommandData;
import ru.java.device.DeviceDriver;
import ru.java.device.DeviceFactory;
import ru.java.device.State;
import ru.java.store.JdbcStorage;
import ru.java.store.classes;

/**
 * Servlet implementation class CommandServlet
 */
public class CommandServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CommandServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 * jdbc.url=jdbc:postgresql://localhost:5432/taskdb1
jdbc.driver_class=org.postgresql.Driver
jdbc.username=root
jdbc.password=root
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		JdbcStorage storage = new JdbcStorage();
		BufferedReader reader = request.getReader();
		Gson gson = new Gson();
		RemoteCommandData res =  gson.fromJson(reader, RemoteCommandData.class);
		DeviceDriver devDriver = DeviceDriver.getInstance(storage);
   	    State state;
				try {
					state = devDriver.turn(res.operation);
					res.setOperation(state.getNotify());
				} catch (InstantiationException e) {
					// TODO Auto-generated catch block
					res.setOperation("InstantiationException!");
					e.printStackTrace();
				} catch (IllegalAccessException e) {
					// TODO Auto-generated catch block
					res.setOperation("IllegalAccessException!");
					e.printStackTrace();
				} catch (IllegalArgumentException e) {
					// TODO Auto-generated catch block
					res.setOperation("IllegalArgumentException!");
					e.printStackTrace();
				} catch (InvocationTargetException e) {
					res.setOperation("InvocationTargetException!");
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (NoSuchMethodException e) {
					// TODO Auto-generated catch block
					res.setOperation("NoSuchMethodException!");
					e.printStackTrace();
				} catch (SecurityException e) {
					res.setOperation("SecurityException!");
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (ClassNotFoundException e) {
					res.setOperation("ClassNotFoundException! "+e.getMessage());
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				finally{
					response.getWriter().write(gson.toJson(res));		
					storage.close();
				}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
