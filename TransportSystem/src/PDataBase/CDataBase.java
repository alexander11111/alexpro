package PDataBase;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Connection;
public class CDataBase {
	   private Connection cn;
	   private String strUrl;
	   private String strUserName;
	   private String strPassword;
	   private String strDriver;
       public CDataBase(String strUrl,String strUserName,String strPassword,String strDriver){
			this.strUrl      = strUrl;
			this.strUserName = strUserName;
			this.strPassword = strPassword;
			this.strDriver   = strDriver;
       }
       private Connection connect() throws InstantiationException, IllegalAccessException, ClassNotFoundException, SQLException{
			cn = null; 
			Driver  dr = (Driver)Class.forName(strDriver).newInstance();
			return cn = (Connection)DriverManager.getConnection(strUrl, strUserName, strPassword);
       }
       public boolean ConnectToDB(){
  			try {
  				cn = null;
				cn = connect();
			} catch (InstantiationException | IllegalAccessException
					| ClassNotFoundException | SQLException e) {
				e.getStackTrace();
				//return false;
			}
  			return true;
       }
       public Connection getConnection(){
    	   return cn;
       }
}
