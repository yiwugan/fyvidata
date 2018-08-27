package ggan.fyvi;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Base64;
import java.util.List;

public class DbGenerator {

	public static void main(String[] args) {
		try {
			List<String> locs=readTextFile("z:/allLocation.txt");
			System.out.println("DbGenerator.main():"+locs.get(0));
			String l=base64((locs.get(0).split("%",-1))[0]);
			System.out.println("DbGenerator.main():"+l);
			List<String> q=dbQuery("select * from locations where cname=?",new String[] {l});
			System.out.println("DbGenerator.main():"+q.get(0) );
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public static List<String> readTextFile(String fileName) {
		List<String> ret = new ArrayList<String>();
		try {
			File f = new File(fileName);
			if (f.isFile() && f.exists()) {
				InputStreamReader read = new InputStreamReader(new FileInputStream(f), "gbk");
				BufferedReader reader = new BufferedReader(read);
				String line;
				while ((line = reader.readLine()) != null) {
					if (!line.isEmpty() && !line.startsWith("//"))
						ret.add(line);
				}
				read.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return ret;
	}

	public static String base64(String s) throws Exception {
		return Base64.getEncoder().encodeToString(s.getBytes("gbk"));
	}

	
	
	
	private static Connection dbConnect() throws Exception {
		// SQLite connection string
		String url = "jdbc:sqlite:z:/fyvi.db";
		Connection conn = null;
		conn = DriverManager.getConnection(url);
		return conn;
	}

	public static void dbInsertUpdate(String sql, String[] params) throws Exception {
		Connection conn = dbConnect();
		PreparedStatement stmt = conn.prepareStatement(sql);
		for (int i = 1; i <= params.length; i++) {
			stmt.setString(i, params[i-1]);
		}
		stmt.executeUpdate();
		conn.close();
	}
	
	public static List<String> dbQuery(String sql, String[] params) throws Exception {
		Connection conn = dbConnect();
		PreparedStatement stmt = conn.prepareStatement(sql);
		for (int i = 1; i <= params.length; i++) {
			stmt.setString(i, params[i-1]);
		}

		ResultSet rs = stmt.executeQuery();
		List<String> ret = new ArrayList<String>();
		ResultSetMetaData rsmd = rs.getMetaData();
		int columnsNumber = rsmd.getColumnCount();
		
		while (rs.next()) {
			StringBuffer sb=new StringBuffer();
			for (int i = 1; i <=columnsNumber; i++) {
				sb.append(rs.getString(i));
				if (i!=columnsNumber)
					sb.append(",");
			}
			ret.add(sb.toString());
		}
		conn.close();
		return ret;
	}
	
}
