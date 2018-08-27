#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("������", ({ "wood cage", "cage", "woodcage" }) );
        set_weight(150000);
        set("no_get", 1);
        set("no_drop", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ò�ͬľ�ϼ������������ɵ�ľ��������������׽���
����Ҫ�Ȱ�װ����������죩��\n");
                set("value", 20000);
        set("material", "wood");
    }
        ::init_item();
} 
void init(){
        if(this_player()==environment()) {
        add_action("do_install", "install");
    }
} 
int do_install(string arg){
        object me, arrow;
        
        me = this_player();
        if(!arg || (arg != "wood cage" && arg != "cage" && arg != "woodcage")){
                return notify_fail("��Ҫװʲô��\n");
        }
        if(present("wood cage", environment(me))){
                return notify_fail("�㷢�������Ѿ���װ�˴��\n");
        }
        if( environment(me)->query("short") != "��ɳ��"){
                return notify_fail("���ﲻ�ʺϰ�װ���\n");
        }
        if(me->query("kee") < 100) {
                return notify_fail("��ʵ��̫���ˣ�����Ϣһ�°ɡ�\n");
   }
        tell_object(me, HIG"����ϸ�ذ���������װ�����ڻ�ɳ�£���ϸ�ĵ�Ĩȥ���ܻ�ɳ�ϵ��㼣��\n"NOR);
        message("vision", me->name()+"�ڻ�ɳ����һ�ǲ�֪�ڹĵ�ʲô������\n", environment(me), me);
        set("long", "��ɳ���ƺ���ʲô������");
        this_object()->move(environment(me));
        set("owner", me->query("id"));
        set("installed", 1);
        me->receive_damage("kee", 100);
        return 1;
}     
