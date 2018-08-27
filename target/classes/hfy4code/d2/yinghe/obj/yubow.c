#include <ansi.h>
inherit ITEM;
int shoot(object me);
void create()
{
        set_name(HIC"�������"NOR, ({ "crossbow", "jade bow", "yu bow" }) );
        set_weight(70000);
        set("no_shown", 1);
        set("no_get", 1);
        set("no_drop", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�
Ҳ����԰�װ����������죩���ԡ�\n");
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
int do_install(string arg){
        object me, arrow;
        int i;
        
        me = this_player();
        if(!arg || arg != "bow" && arg != "crossbow"){
                return notify_fail("��Ҫװʲô��\n");
   }
        if(present("installed bow", environment(me)) || environment(me)->query("no_fight")){
                return notify_fail("��û�ҵ����ʵĵط���\n");
        }
        arrow = present("small arrow", me);
        if(!objectp(arrow)){
                return notify_fail("ȱ�ټ�ͷ��û�а취��װ��\n");
        } else {
                i = arrow->query_amount();
                if(i < 10){
                        return notify_fail("ȱ�ټ�ͷ��û�а취��װ��\n");
                }
        }
        if(me->query("kee") < 100) {
                return notify_fail("��ʵ��̫���ˣ�����Ϣһ�°ɡ�\n");
        }
        if(query("installed")){
                delete("installed");
                tell_object(me, HIG"�����˸����ν�����ϸ�ѹ���װ�á�\n"NOR);
                this_object()->move(environment(me));
                set("owner", me->query("id"));
                me->receive_damage("kee", 50);
                this_object()->set("installed");
                return 1;
        }       
        if(me->query_str() > 45 ) {
                tell_object(me, HIG"�����˸����ν��䣬���������������ѹ�����������ϸ�İ�װ���˼�ͷ��\n"NOR);
                set("long", "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�\n");
        } else {
                message_vision("$N������������ȴ˿��������\n", me);
                return 1;
        }
        arrow->set_amount(i-10);
        this_object()->move(environment(me));
        set("owner", me->query("id"));
        set("installed", 1);
        me->receive_damage("kee", 50);
        return 1;
} 
int do_search(){
   object me, bow;
        int i;
        
        me = this_player();
        i = me->query_skill("perception");
        if(!present("jade bow", environment(me))){
                return 0;
        }
        tell_object(me, "����ϸ������������һ��.\n");
        
        if(random(i) < 20) {
                tell_object(me, "��ʲô��û���ҵ���\n");
        } else {
                tell_object(me, "����һ�����εĽ����ҵ�һ���������\n");
                this_object()->move(me);
        }
        return 1;
} 
int shoot(object me){
        int kee, i, j;
        string *limbs, limb, output, msg;
        i = me->query_skill("perception");
        if(me->query("id") == query("owner")){
                return 0;
        }
        if(environment(me) != environment(this_object())){
                return 0;
        }
        limbs = me->query("limbs");
        message_vision("һ�����ƿ�֮������������\n", me);
        for(j=0; j<10; j++){
                message_vision(CYN"ֻ�������������죬һ֧��������$N��\n"NOR, me);
                if( random(i) < 20 ){
                        if(!random(8)) {
                                message_vision(YEL"��ͷʧȥ׼ͷ���պô�$N���Բ�����\n"NOR, me);
                        } else {
                                limb = limbs[random(sizeof(limbs))];
                                msg = HIR"$N��ܲ�����������$N��$l��\n"NOR;
                                output = replace_string(msg, "$l", limb);
                                message_vision(output, me);
                           kee = me->query("eff_kee");
                                me->receive_wound("kee", kee/20, me);
                                COMBAT_D->report_status(me);
                        }
                } else {
                        message_vision("$N�����Ʒ�֮����һ��ת��ʱ�ܿ���\n", me);
                }
        } 
        delete("installed");
        set("long", "һ���ƹ�����Ĺֶ������ƺ�������������׽����ġ�
Ҳ����԰�װ����������죩���ԡ�\n");
        return 1;
}      
