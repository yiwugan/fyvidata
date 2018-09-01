package ggan.fyvi;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.Base64;
import java.util.List;

public class DbGenerator {

	public static void main(String[] args) {
		try {
			System.out.println("DbGenerator.main() enter");
			loadAllNpcs();
			loadETasks();
			System.out.println("DbGenerator.main() exit");
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	
	
	public static void loadETasks() throws Exception {
		List<String> locs = readTextFile("z:/etask.txt");
		// System.out.println("DbGenerator.main():" + locs.get(0));
		List<String> found = new ArrayList<String>();
		List<String> notFound = new ArrayList<String>();
		for (String string : locs) {
			String[] fs = string.split(",");
			fs[0] = base64(fs[0]);
			System.out.println("--->"+string+","+fs[0]);
			List<String> n = dbQuery(
					"select npcs.ename,locations.fullpath from npcs,objtolocation,locations where npcs.id=objtolocation.objid and objtolocation.locationid=locations.id and npcs.cname=?",
					new String[] { fs[0] });
			if (n == null || n.size() == 0) {
				notFound.add(string);
				// System.out.println("Not found:" + string);
			} else {
				found.add(String.join(",", n));
				// System.out.println("Found:" + n.get(0));
			}
		}
		for (String string : notFound) {
			System.out.println("Not found:" + string);
		}
		writeTextFile("z:/work/etask-notfound.txt", notFound);
		
		for (String string : found) {
			System.out.println("Found:" + string);
		}
		writeTextFile("z:/work/etask-found.txt", found);

	}

	public static void loadAllNpcs() throws Exception {
		List<String> locs = readTextFile("z:/allNpc.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));
		
		for (String string : locs) {
			System.out.println("DbGenerator.loadAllNpcs():"+string);
			String[] fs = string.split(",");
			String[] ps=new String[4];
			ps[0] = base64(fs[0]);
			ps[1]=fs[1];
			ps[2]=fs[2];
			ps[3]=fs[3];
			dbInsertUpdate("insert into npcs (cname,ename,area,id) values(?,?,?,?)", ps);
		}
	}

	public static void loadAllTasks() throws Exception {
		List<String> locs = readTextFile("z:/allTask.txt");
		System.out.println("DbGenerator.main():" + locs.get(0));
		for (String string : locs) {
			String[] fs = string.split(",");
			fs[0] = base64(fs[0]);
			fs[1] = base64(fs[1]);
			dbInsertUpdate("insert into tasks (ownercname,cname,ename) values(?,?,?)", fs);
		}
	}

	public static void writeTextFile(String fileName, List<String> lines) {
		try {
			File f = new File(fileName);
			OutputStreamWriter w = new OutputStreamWriter(new FileOutputStream(f), "gbk");
			BufferedWriter wr = new BufferedWriter(w);
			for (String string : lines) {
				wr.write(string+"\n");
			}
			wr.close();
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

	public static int dbInsertUpdate(String sql, String[] params) throws Exception {
		Connection conn = dbConnect();
		PreparedStatement stmt = conn.prepareStatement(sql);
		for (int i = 1; i <= params.length; i++) {
			stmt.setString(i, params[i - 1]);
		}
		int ret = stmt.executeUpdate();
		conn.close();
		return ret;
	}

	public static List<String> dbQuery(String sql, String[] params) throws Exception {
		Connection conn = dbConnect();
		PreparedStatement stmt = conn.prepareStatement(sql);
		for (int i = 1; i <= params.length; i++) {
			stmt.setString(i, params[i - 1]);
		}

		ResultSet rs = stmt.executeQuery();
		List<String> ret = new ArrayList<String>();
		ResultSetMetaData rsmd = rs.getMetaData();
		int columnsNumber = rsmd.getColumnCount();

		while (rs.next()) {
			StringBuffer sb = new StringBuffer();
			for (int i = 1; i <= columnsNumber; i++) {
				sb.append(rs.getString(i));
				if (i != columnsNumber)
					sb.append(",");
			}
			ret.add(sb.toString());
		}
		conn.close();
		return ret;
	}

}
