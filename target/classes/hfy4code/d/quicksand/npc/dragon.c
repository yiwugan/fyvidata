 inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
        set_name("ɳ������", ({ "hibernating dragon", "dragon" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 200);
        set("long", "�Ȿ��һ���ں�����������������Ϊ�׺�ɣ��ı�Ǩ��ԭ���ĺ������
��ɳĮ�����������ݷ�������Ҳ��֪���м�ǧ�������ˡ� \n");
        
        set("cor", 52);
        set("cps", 62);
        set("str",70);
        set("boss",1);
        set("max_kee", 100000);
        set("max_gin", 100000);
        set("max_sen", 100000);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��", "צ��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(20));
        set("chat_msg_combat", ({
        (: big_blowing :)
        }) ); 
        set("combat_exp", 5000000+random(2000000));
        
        set_temp("apply/attack",360);
        set_temp("apply/damage",300);
        set_temp("apply/armor", 340);
        set_temp("apply/dodge",360); 
        setup();
        carry_object("/obj/money/gold")->set_amount(10);
} 
void init() {
        add_action("do_kill", "kill");
}   
int do_kill(string arg) {
        object me;
   int i, kee;
        me = this_player();
        if (!arg || (arg != "dragon" && arg != "hibernating dragon")) {
                return 0;
        }
        i = me->query_temp("out_river") - me->query_temp("in_river");
        if(this_object()->is_fighting()) {
                return 0;
        }
        kee = query("eff_kee");
        if(i >= 60 ) {
                if(me->query("str") > 35){
                        message_vision(HIW"$N����һ������ɳ��������ͷ������˯�е�ɳ���������޷���֮��������鴤�˼��¾Ͳ����ˡ�\n"NOR, me);
                        this_object()->set_temp("last_damage_from", me);
                        this_object()->die();           
                        return 1;
                } else {
                        message_vision(HIR"$N����һ������ɳ��������ͷ����ɳ������΢�յ�˫����Ȼ������\n"NOR, me);
                        tell_object(me, "�������ͷһ�����ϵ�����һ����\n");
                        this_object()->receive_damage("kee", kee*9/10);
                }
        } else if (i >=30 ) {
                message_vision(HIG"$N����ͻȻ�ӿ죬��Ȼ�乥��ɳ��������\n", me);
                this_object()->receive_damage("kee", kee/2);
        } 
        return 0;
}
int big_blowing()
{
        
        remove_call_out("hurting");
        message_vision(HIR"\n\n$Nɳ���������Ϻ�Ȼ���������ĺ�⣬����ȥ��ͬһ���Ž����õ�������\n\n"NOR,
                        this_object());
        call_out("hurting",random(5)+2); 
        return 1;
} 
int hurting()
{
        int i;
        int dam;
   object *inv;
        message_vision(HIR"\n\n$Nɳ������˫Ŀ֮������ҫ�������ȫ�����հ�ؾ�ʹ��\n\n"NOR,this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(300)+100 - inv[i]->query_temp("apply/armor_vs_fire");
        if(dam <0) dam = 0;
        inv[i]->receive_wound("kee",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
} 
int valid_leave(object me, string dir) {
        if (dir == "down") {
                me->set_temp("in_water", time());
        }
        return 1;
} 
void die()
{
        object rstone, me; 
        if(objectp(me=query_temp("last_damage_from"))) { 
                if(!me->query("m_success/�����൤")){
                me->set("m_success/�����൤",1);
                me->add("score",300);
                        me->add("combat_exp", 10000);
                        me->add("potential", 1000);
                }
                rstone = new("/obj/specials/stone/rstone");
                if (objectp(rstone) && me->query("����B/�䵱_��Ҷ") && !me->query("stone_mark/rstone")) {
                        message_vision(HIR"\nһ�����ɳ������˫Ŀ�����¸պõ���$n���С�\n"NOR, this_object(), me);
                        rstone->move(me);
                        me->set("stone_mark/rstone", 1);
                } else {
                        message_vision(HIR"\nһ�����ɳ������˫Ŀ�����£�˲���ɫ�Ĺ�â���������ܣ�ת������������ȥ��\n"NOR,
                                this_object());
                        environment(this_object())->tell_exit(me);      
                }
   } 
        ::die();
}    
