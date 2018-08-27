// by xiaolang@fy.sumxin.com
#include <armor.h>
#include <ansi.h>
inherit WEAR; 
void create() {
        if(clonep(this_object())) {
                destruct(this_object());
                return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
        }
        set("timestamp","STAMP");
} 
void init_cloth() {
        if(!clonep()) {
                set("armor_type", TYPE_CLOTH);
                set("armor_worn", WORN_CLOTH);
                set("armor_prop/not_naked", 1);
        }
        ::init_wear();
} 
void init() {
        add_action("do_inset", "inset");
} 
int do_inset(string arg) {
	object me, cloth, stone,ob;
        string obj, item, p;
        string newfile,timestamp,filename;
        int i,j,h;
        
        me = this_player();
        
        if(!arg) {
                return notify_fail("��Ҫ��Ƕʲô������\n");
        }
        if(!sscanf(arg, "%s in %s", item,obj)) {
                return notify_fail("��Ҫ��ʲô��Ƕ�����(inset xxx in xxx)\n");
        }
        cloth = present(obj, me);
        stone = present(item, me);
        
        if(!objectp(cloth) || !objectp(stone)){
                return notify_fail("��û����Щ������\n");
        }
        if( !cloth->query("hole") ) {
                return notify_fail(cloth->name()+"�Ѿ�û�ж���İ��۹�����Ƕ�ˡ�\n");
        }
        if(!stone->query("inset")){
                return notify_fail(stone->name()+"������������Ƕ��\n");
        }
        i=(int)stone->query("level");
        j=(int)cloth->query("level");
        if(!cloth->query("hole")) h=0;
        h=(int)cloth->query("hole");
        p=(string)stone->query("����");

	newfile = read_file("/data/questarmor/whitecloth.c");
        timestamp = sprintf("%c%c%c%c%c%c%c",'a'+random(20),'a'+random(20),'a'+random(20),
        'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20));
        
        newfile = replace_string( newfile, cloth->name(), "������"+cloth->name());
        newfile = replace_string( newfile, "STAMP", timestamp);
        filename = DATA_DIR+"questarmor/"+timestamp + ".c";
        if(!write_file(filename, newfile,1))
                return 0;
        ob = new(filename);
        ob->set("hole",h-1);
        ob->set("level",j+1);
        ob->set("name","������"+cloth->name());
        ob->add("armor_prop/armor",100);
        ob->add("base_armor",100);
        ob->set("no_sell",1);
        ob->set("no_drop",1);
        ob->set("no_pawn",1);
        ob->save();
        ob->restore();
        ob->move(me);
        destruct(stone);
        destruct(cloth);
        return 1;
}       

string query_save_file()
{
/*        string id;
        id = query("owner");
        if( !stringp(id) ) return 0; */
        return sprintf(DATA_DIR "questarmor/%s", query("timestamp"));
}
int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;
        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}
int query_autoload() { return 1; } 