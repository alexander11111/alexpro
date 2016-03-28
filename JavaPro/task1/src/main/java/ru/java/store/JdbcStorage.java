package ru.java.store;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import ru.java.service.SettingsDB;

public class JdbcStorage implements IStorage {
	private Connection connection=null;

	@Override
	public List<classes> getAllClass() 
	{
		List<classes> classNames = new ArrayList<classes>();   
	    try (final PreparedStatement stat = this.connection.prepareStatement("SELECT * from classes"))
        {
          try(final ResultSet rs = stat.executeQuery();)
          {
           while(rs.next())
           {
            classNames.add(new classes(rs.getInt("id"),rs.getString("classname")));
           }
          }
        }
       catch(SQLException e)
	   {
         e.printStackTrace();
       }
     return classNames;
	}
	
	@Override
	public classes getClassName(String name) {
		// TODO Auto-generated method stub
		classes className=null;
		/*try (final PreparedStatement stat = this.connection.prepareStatement("SELECT classes.id,classes.classname"+
                                                    "FROM classes INNER JOIN keywords"+
                                                    "ON classes.id = keywords.binded_class"+
                                                    "WHERE keywords.keyword=(?)");)
                                                    */
  	   try (final PreparedStatement stat = this.connection.prepareStatement("SELECT classes.id,classes.classname from classes,keyword"+
                                                    " WHERE classes.id=keyword.binded_class and keyword.keyword=(?)"))
	   {
		    stat.setString(1, name);
		    try(final ResultSet rs = stat.executeQuery();){
			 while(rs.next()){
			   className = new classes(rs.getInt("id"),rs.getString("classname"));
			 }
		    }
		}
		catch(SQLException e){
			e.printStackTrace();
		}
		return className;
	}
	
	public JdbcStorage(){
		SettingsDB settings = SettingsDB.getInstance();
		try {
			//Class.forName("com.mysql.jdbc.Driver");
			Class.forName(settings.value("jdbc.driver_class"));
			String url = settings.value("jdbc.url");
			String login = settings.value("jdbc.username");
			String password = settings.value("jdbc.password");
			this.connection = DriverManager.getConnection(url,login,password);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
				//DriverManager.getConnection(arg0);
 catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void close() {
		// TODO Auto-generated method stub
		try {
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
