package PDataBase;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class CReadWriter {
	public Connection cn; 
	public Statement  st;
	public ResultSet  rs;
	public CReadWriter(Connection cn){
		this.cn = cn;
		try{
		st = cn.createStatement();
		}
		catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void Write(String strSQL)
	{
		try{
		  st.executeUpdate(strSQL);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	public ResultSet Read(String strSQL)
	{
		try{
			rs = st.executeQuery(strSQL);
			return rs;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public void closeRW(){
		try{
		st.close();
		cn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}

