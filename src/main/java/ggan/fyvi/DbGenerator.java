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
import java.util.Collection;
import java.util.List;

import org.apache.commons.io.FileUtils;

public class DbGenerator {

	public static String baseDir = "/home/ggan/workspace/fyvidata/src/main/resources/";

	public static void main(String[] args) {
		try {
			System.out.println("DbGenerator.main() enter");
			updateNpcLocationPath();
//			loadNameFoundNpcs();
//			loadAddNpcs();
//			loadAddonLocationsObjs();
//			loadNotFoundNpcs();
//			loadETasks();
//			generateNpcFlyFlag();
//			loadAllNpcs();
//			loadETasks();
			System.out.println("DbGenerator.main() exit");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void updateNpcLocationPath() throws Exception {
		List<String> npcLocPaths = dbQuery(
				"select npcs.id, locations.fullpath from locations,npcs,objtolocation where locations.id=objtolocation.locationid and npcs.id=objtolocation.objid",
				new String[] {});
		for (String string : npcLocPaths) {
			String[] rs = string.split(",", -1);
			String[] params = new String[] { rs[1], rs[0] };
			dbInsertUpdate("update npcs set locationpath=? where id=?", params);
		}
	}

	public static void loadNameFoundNpcs() throws Exception {
		List<String> locs = readTextFile(baseDir + "work/etask-namefound.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));

		for (String string : locs) {
			System.out.println("DbGenerator.loadNameFoundNpcs():" + string);
			String[] fs = string.split(",", -1);
			String[] ps = new String[2];
			ps[0] = fs[3];
			ps[1] = base64(fs[0]);

			dbInsertUpdate("update npcs set questpath=? where cname=? ", ps);
		}
	}

	public static void loadNotFoundNpcs() throws Exception {
		List<String> locs = readTextFile(baseDir + "work/etask-namenotfound.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));

		for (String string : locs) {
			System.out.println("DbGenerator.loadNpcs():" + string);
			String[] fs = string.split(",", -1);
			String[] ps = new String[6];
			ps[0] = base64(fs[0]);
			ps[1] = fs[1];
			ps[2] = fs[2];
			ps[3] = fs[3];
			ps[4] = fs[4];
			ps[5] = "";
			if (fs[5] == "fly") {
				ps[5] = "true";
			}

			dbInsertUpdate("insert into npcs (cname,ename,area,id,questpath,flyable) values(?,?,?,?,?,?)", ps);
		}
	}

	public static void generateNpcFlyFlag() throws Exception {
		String base = "/home/ggan/grive/hfy4code/d/";

		Collection<File> allFiles = FileUtils.listFiles(new File(base), new String[] { "c" }, true);
		System.out.println("DbGenerator.generateNpcFlyFlag():" + allFiles.size());
		for (File file : allFiles) {
			boolean fly = isFlyable(file.getAbsolutePath());
			if (fly) {
				String npcid = file.getAbsolutePath().replaceAll(base, "");
				npcid = npcid.replaceAll("\\.c", "");
				System.out.println(npcid + ":" + fly);
				dbInsertUpdate("update npcs set flyable='true' where id=?", new String[] { npcid });
			}
		}
	}

	public static boolean isFlyable(String filename) throws Exception {
		List<String> lines = readTextFile(filename);
		for (String string : lines) {
			if (string.indexOf("set(\"max_force\"") > 0)
				return true;
		}
		return false;
	}

	public static void generateAddonLocationsPath() throws Exception {
		List<String> locs = dbQuery("select * from locations where fullpath = \"\"", null);

		for (String string : locs) {
			System.out.println(string);
			String[] locInfo = string.split(",", -1);
			List<String> paths = dbQuery(
					"select fullpath from locations where cname =? and area=? and cdesc=? and fullpath !=\"\"",
					new String[] { locInfo[0], locInfo[4], locInfo[3] });
			System.out.println("---> " + paths.size());
			if (paths.size() > 0) {
				dbInsertUpdate("update locations set fullpath=? where id=?", new String[] { paths.get(0), locInfo[1] });
			}
		}
	}

	public static void loadAddonLocationsObjs() throws Exception {
		List<String> locs = readTextFile(baseDir + "allLocationAdd.txt");

		for (String string : locs) {
			System.out.println("--->" + string);
			String[] fs = string.split("%", -1);
			String obj = fs[4];
			String id = fs[2];
			String[] objs = obj.split("\\|");
			for (int i = 0; i < objs.length; i++) {
//				System.out.println("DbGenerator.loadAddonLocationsObjs():"+objs[i]+","+id);
				dbInsertUpdate("insert into objtolocation (objid,locationid) values(?,?)",
						new String[] { objs[i], id });
			}
		}
	}

	public static void loadETasks() throws Exception {
		List<String> locs = readTextFile(baseDir + "etask.txt");
		// System.out.println("DbGenerator.main():" + locs.get(0));
		List<String> found = new ArrayList<String>();
		List<String> notFound = new ArrayList<String>();
		for (String string : locs) {
			String[] fs = string.split(",");
			fs[0] = base64(fs[0]);
			System.out.println("--->" + string + "," + fs[0]);
			List<String> n = dbQuery(
					"select npcs.ename,locations.fullpath from npcs,objtolocation,locations where npcs.id=objtolocation.objid and objtolocation.locationid=locations.id and locations.fullpath !=\"\" and npcs.cname=?",
					new String[] { fs[0] });
			if (n == null || n.size() == 0) {
				notFound.add(string);
				// System.out.println("Not found:" + string);
			} else {
				found.add(String.join(",", n));
				// System.out.println("Found:" + n.get(0));
			}
		}
//		for (String string : found) {
//			System.out.println("Found:" + string);
//		}
		writeTextFile(baseDir + "work/etask-path-found.txt", found);

		List<String> nameFound = new ArrayList<String>();
		List<String> nameNotFound = new ArrayList<String>();
		for (String string : notFound) {
			String[] fs = string.split(",");
			fs[0] = base64(fs[0]);
//			System.out.println("--->" + string + "," + fs[0]);
			List<String> n = dbQuery("select * from npcs where cname=?", new String[] { fs[0] });
			if (n == null || n.size() == 0) {
				nameNotFound.add(string);
				// System.out.println("Not found:" + string);
			} else {
				nameFound.add(string);
				// System.out.println("Found:" + n.get(0));
			}
		}

//		for (String string : notFound) {
//			System.out.println("Not found:" + string);
//		}
		writeTextFile(baseDir + "work/etask-namenotfound.txt", nameNotFound);
		writeTextFile(baseDir + "work/etask-namefound.txt", nameFound);

	}

	public static void loadAddonLocations() throws Exception {
		List<String> locs = readTextFile(baseDir + "allLocationAdd.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));

		for (String string : locs) {
			System.out.println("DbGenerator.loadAllNpcs():" + string);
			String[] fs = string.split("%", -1);
			String[] ps = new String[5];
			ps[0] = base64(fs[0]);
			ps[1] = fs[1];
			ps[2] = fs[2];
			ps[3] = base64(fs[3]);
			ps[4] = fs[5];
			dbInsertUpdate("insert into locations (cname,area,id,cdesc,fullpath) values(?,?,?,?,?)", ps);
		}
//		writeTextFile(baseDir+"allLocationAdd.txt",locs);
	}

	public static void generateAddonLocations() throws Exception {
		List<String> locs = readTextFileAll(baseDir + "allLocation.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));

		for (String string : locs) {
			System.out.println("DbGenerator.loadAllNpcs():" + string);
			String[] fs = string.split("%");
			String[] ps = new String[4];
			ps[0] = base64(fs[0]);
			ps[1] = fs[1];
			ps[2] = fs[2];// loadAllNpcs();

			ps[3] = fs[3];
//			System.out.println(string);
//			dbInsertUpdate("insert into npcs (cname,ename,area,id) values(?,?,?,?)", ps);
		}
		writeTextFile(baseDir + "allLocationAdd.txt", locs);
	}

	public static void loadAllNpcs() throws Exception {
		List<String> locs = readTextFileAll(baseDir + "allNpc.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));

		for (String string : locs) {
			System.out.println("DbGenerator.loadAllNpcs():" + string);
			String[] fs = string.split(",");
			String[] ps = new String[4];
			ps[0] = base64(fs[0]);
			ps[1] = fs[1];
			ps[2] = fs[2];
			ps[3] = fs[3];
			dbInsertUpdate("insert into npcs (cname,ename,area,id) values(?,?,?,?)", ps);
		}
	}

	public static void loadAddNpcs() throws Exception {
		List<String> locs = readTextFile(baseDir + "allNpcAdd.txt");
//		System.out.println("DbGenerator.main():" + locs.get(0));

		for (String string : locs) {
			System.out.println("DbGenerator.loadAllNpcs():" + string);
			String[] fs = string.split(",");
			String[] ps = new String[4];
			ps[0] = base64(fs[0]);
			ps[1] = fs[1];
			ps[2] = fs[2];
			ps[3] = fs[3];
			dbInsertUpdate("insert into npcs (cname,ename,area,id) values(?,?,?,?)", ps);
		}
	}

	public static void loadAllTasks() throws Exception {
		List<String> locs = readTextFile(baseDir + "allTask.txt");
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
				wr.write(string + "\n");
			}
			wr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static List<String> readTextFileAll(String fileName) {
		List<String> ret = new ArrayList<String>();
		try {
			File f = new File(fileName);
			if (f.isFile() && f.exists()) {
				InputStreamReader read = new InputStreamReader(new FileInputStream(f), "gbk");
				BufferedReader reader = new BufferedReader(read);
				String line;
				while ((line = reader.readLine()) != null) {
//					if (!line.isEmpty() && !line.startsWith("//"))
//						ret.add(line);
					if (line.startsWith("//") && (line.indexOf("/npc/") > 0 || line.indexOf("/obj/") > 0)) {
						line = line.replaceAll("//", "");
						ret.add(line);
					}
				}
				read.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return ret;
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
					if (!line.isEmpty() && !line.startsWith("//") && !line.startsWith("--"))
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
		String url = "jdbc:sqlite:" + baseDir + "fyvi.db";
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
		if (params != null) {
			for (int i = 1; i <= params.length; i++) {
				stmt.setString(i, params[i - 1]);
			}
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
