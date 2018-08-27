 // Room: weapon_array.c --- by neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        object table, key;
        set("short", "������ɱ��");
        set("long", @LONG
һ�乹�����ص�ʯ�ݡ�ʯ��������һ��ʯ̨��ʯ�ݵĽ�������ĸ�ʽ�����ı�
��������һЩʯ��ɢ���ڵأ������з�λ�Ų�����һ�ӽ����;���ɱ�����ᣬ���
�̹ǡ� 
LONG);
        set("objects", ([
                __DIR__"obj/jade_table" : 1,
                __DIR__"npc/wa_guard1" : 1,
                __DIR__"npc/wa_guard2" : 1,
                __DIR__"npc/wa_guard3" : 1,
                __DIR__"npc/wa_guard4" : 1,
                __DIR__"npc/wa_guard5" : 1,
                __DIR__"npc/wa_guard6" : 1,
                __DIR__"npc/wa_guard7" : 1,
                __DIR__"npc/wa_guard8" : 1,
        ]));
        set("indoors","yinghe");
        set("exits",([
                "south":__DIR__"weaponroom",
                "north":__DIR__"foodroom",
        ]) );
        //}} 
        setup();
        table = present("jade table", this_object());
        key = new(__DIR__"obj/goldenkey");
        key->move(table);
} 
void init(){
        add_action("do_get", "get");
} 
int do_get(string arg){
    string what,where;
        object guard;
   if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    if(where == "table" || where == "jade table" || where == "stone" || where == "��ʯ̨" || where == "ʯ̨"){
        guard = present("key guard", this_object());
        if(objectp(guard)){
                message_vision(HIY"$N��$n��ȵ�����ʮ������û�˸Ҷ�����ɽׯһ��һľ�������������˴󵨣���\n\n"NOR,
                                guard,this_player());
                guard->kill_ob(this_player());
                this_player()->start_busy(1);
                return 1;
        } else {
                return 0;
        }
    }
    return 0;
} 
void reset(){
        object table, key, *inv;
        int i;
        
        ::reset();
        
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if( userp( inv[i]) ) return;
        }
        add("refresh_counter", 1);
        table = present("jade table", this_object());
        if ( (int) query("refresh_counter") > 2 ) {
                key = new(__DIR__"obj/goldenkey");
                key->move(table);
                delete("refresh_counter");
        }
        return;
}
