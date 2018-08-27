#include <ansi.h>
inherit ITEM;
string bow_desc();
void create()
{
        set_name(YEL"���Ƶع�"NOR, ({ "ground bow", "bow", "installed bow" }) );
        set_weight(70000);
        set("no_shown", 1);
        set("no_get", 1);
        set("no_drop", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", (: bow_desc :));
                set("value", 1000);
        set("material", "metal");
    }
        ::init_item();
} 
void init(){
        object me;
        
        me = this_player();
        if(this_player()==environment()) {
        add_action("do_install", "install");
    }
        add_action("do_search", "search");
        if(query("installed") && environment(me) == environment(this_object())){
                call_out("shoot", 1, me);       
        }
} 
string bow_desc(){
        if (query("installed")){
                return "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�\n";
        } else {
                return "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�
Ҳ����԰�װ����������죩���ԡ�\n";
        }       
} 
int do_install(string arg){
        object me, arrow;
        
        me = this_player();
        if(!arg || arg != "bow" && arg != "ground bow"){
                return notify_fail("��Ҫװʲô��\n");
        }
        if(present("installed bow", environment(me)) || environment(me)->query("no_fight")){
                return notify_fail("��û�ҵ����ʵĵط���\n");
        }
        arrow = present("giant arrow", me);
        if(!objectp(arrow)){
                return notify_fail("ȱ�ټ���û�а취װ��\n");
        }
        if(me->query("kee") < 100) {
                return notify_fail("��ʵ��̫���ˣ�����Ϣһ�°ɡ�\n");
        }
        if(query("installed")){
                tell_object(me, HIG"�����˸����ν�����ϸ�ѹ���װ�á�\n"NOR);
                this_object()->move(environment(me));
                set("owner", me->query("id"));
                me->receive_damage("kee", 50);
                return 1;
        }       
        if(me->query_str() > 45 ) {
                tell_object(me, HIG"�����˸����ν��䣬���������������ѹ�����������ϸ�ذ�װ���˼�ͷ��\n"NOR);
                set("long", "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�\n");
        } else {
                message_vision("$N������������ȴ˿��������\n", me);
                return 1;
        }
        destruct(arrow);
        this_object()->move(environment(me));
        set("owner", me->query("id"));
        set("installed", 1);
        me->receive_damage("kee", 50);
        return 1;
} 
int do_search(){
        object me, bow;
   me = this_player();
        if(!present("ground bow", environment(me))){
                return 0;
        }
        tell_object(me, "����ϸ������������һ��.\n");
        
        if(!random(5)) {
                tell_object(me, "��ʲô��û���ҵ���\n");
        } else {
                tell_object(me, "����һ�����εĽ����ҵ�һ�����Ƶع���\n");
                this_object()->move(me);
        }
        return 1;
} 
int shoot(object me){
        int kee, i;
        string *limbs, limb, output, msg; 
        if(environment(me) != environment(this_object())) {
                return 0;
        }
        limbs = me->query("limbs");     
        limb = limbs[random(sizeof(limbs))];
        i = me->query_skill("perception");
        if(me->query("id") == query("owner")){
                return 0;
        }
        if( random(i) < 20){
                msg = HIR"��֪�Ӻδ�����һֻ��������ž����һ��������$N��$l��\n"NOR;
                output = replace_string(msg, "$l", limb);
                message_vision(output, me);
                kee = me->query("eff_kee");
                me->receive_wound("kee", kee/3, me);
                COMBAT_D->report_status(me);
        } else {
                message_vision("һֻ������֪�Ӻ�������$N�����ƿ�֮����һ��ת��ʱ�ܿ���\n", me);
        }
        
        delete("installed");
        set("long", "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�
Ҳ����԰�װ����������죩���ԡ�\n");
   return 1;
}  
int query_autoload() { return 1; }    
