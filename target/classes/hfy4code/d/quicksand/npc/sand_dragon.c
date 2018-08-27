#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
int dragon_attack();
int dragonstun();
int dragonclaw();
int dragonbreath ();
int dragonblow (); 
void create()
{
        set_name("ɳ������", ({ "hibernating dragon", "dragon" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("long", "�Ȿ��һ���ں�����������������Ϊ�׺�ɣ��ı�Ǩ��ԭ���ĺ������
��ɳĮ�����������ݷ�������Ҳ��֪���м�ǧ�������ˡ� \n");
        set("limbs", ({ "��ͷ", "����", "��β", "��צ","����", "����","����" }) );
        set("verbs", ({ "dragonbite","dragonslash","dragonswing","dragonthrow","dragonbreath","dragonpoke" }) );
        
        set("combat_exp", 15000000);
        
        set("cor", 80);
        set("cps", 80);
        set("con",40);
        set("fle",40);
        set("dur",40);
        set("agi",40);
        set("int",80);
        set("age",10000000);
        set("no_curse",1);
        set("str",90);
        set("boss",1);
        
        set("max_kee", 500000);
        set("max_gin", 300000);
        set("max_sen", 300000);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                20:     (: dragon_attack() :),
        ]) );           
        
           set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: dragonclaw() :),
        }) );
        
        set("chat_chance",1);
        set("chat_msg",({
        }) );   
        set_temp("apply/attack", 800);
        set_temp("apply/armor",  200);
        set_temp("apply/dodge",  600);
        set_temp("apply/damage", 50);
        setup();
}  
int dragon_attack(){
        if (random(2)) dragonstun();
        else if (time()>query("dragon/breath")+10) dragonbreath();
        return 1;
}  
int dragonbreath ()     {
        message_vision(HIR"\n\n$N���Ϻ�Ȼ���������ĺ�⣬ת˲�䣬��âԽ��Խǿ�ҡ�����\n\n"NOR,
                        this_object());
        call_out("hurting",8);
        set("dragon/breath",time());
        return 1;
} 
int hurting()   {
        int i,dam;
        object *inv;
        message_vision(HIR"\n\n$Nһ���죬����������ӭ���������������޿��������޿ɱܡ�\n\n"NOR,this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
                if( living(inv[i]))
                if( inv[i]!= this_object()){
                        dam = 2000+random(3000);
                        inv[i]->receive_wound("kee",dam,this_object());
                        COMBAT_D->report_status(inv[i]);
                }
        return 1;
}  
int dragonblow()   {
}  
int dragonstun()        {
        int i,dam;
        object *inv;
        message_vision(HIW"\n\n$N��ֱ������������Ծ�£���ҡ�ض���ɳѨ�����������\n\n"NOR,this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
                if( living(inv[i]))
                if( inv[i]!= this_object()){
                        if (random(this_object()->query("combat_exp"))*5<inv[i]->query("combat_exp"))
                                continue;
                        if (inv[i]->query_busy()<4) inv[i]->start_busy(4);
                        message_vision(YEL"$Nֻ���ĵ����ѣ�Ŀ�ɿڴ����������á�\n"NOR,inv[i]);
                }
        return 1;
}  
int dragonclaw()        {
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        ob->set("bite_time",time());
        enemy=ob->query_enemy();
        me=enemy[random(sizeof(enemy))];
        message_vision(HIG"\n$N���������ǰצ��Ю����֮�ƣ�Ѹ������$n��ͷ��һץ��\n"NOR,ob,me);
        me->receive_wound("kee",2000+random(2000),ob);
        COMBAT_D->report_status(me);
        if (ob->query_busy()<3) ob->start_busy(2);
        return 1;
}  
void die()
{
        object rstone, me,owner,money_reward,skin;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        environment(this_object())->set("dragon_death",time());
   if(objectp(me)) { 
                if(!me->query("m_success/�����൤")){
                        CHANNEL_D->do_sys_channel("info","һ���µ������񻰵ĵ�����������");
                        CHANNEL_D->do_sys_channel("info",sprintf("%s��%s��%s%s%s��", NATURE_D->game_time(),
                                me->query("name"), environment(this_object())->query("short"),"նɱ", name())); 
                        me->set("m_success/�����൤",1);
                        me->add("score",300);
                        me->add("combat_exp",50000);
                        me->add("potential", 10000);
                        money_reward = new("/obj/money/gold");
                        money_reward->set_amount(300);
                        money_reward ->move(me);
                        tell_object(me,WHT"��ϲ��ɱ����ɳ���������㱻������!!!\n"NOR);
                        tell_object(me,WHT"\n����ǻۺ��¸ҽ��������д��̡�\n\n"NOR);
                }
                rstone = new("/obj/specials/stone/rstone");
                skin= new(__DIR__"obj/skin");
                if (objectp(rstone)) {
                        message_vision(HIR"\nһ�����ɳ������˫Ŀ�����¸պõ���$n���С�\n"NOR, this_object(), me);
                        rstone->move(me);
                        skin->move(this_object());
                        me->set("stone_mark/rstone", 1);
                        
                }
        } 
        environment(this_object())->tell_exit();        
        ::die();
}    
