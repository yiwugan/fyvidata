 inherit NPC;
#include <ansi.h>
#include <combat.h>
void create()
{
        set_name("������Ů", ({ "redcloth girl","girl" }) );
        set("gender", "Ů��" );
        set("class", "legend" );
        set("age", 21);
        set("str", 30);
        set("per", 40);
        set("cor", 20);
        set("cps", 20);
        set("con", 30);
        set("int", 30);
        set("max_kee", 6000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("max_force", 5000);
        set("force", 6000);
        set("fle", 20);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 50);
        set("long", "һ������ȥ��ʮ�������Ů������ͤͤ�������ݣ�
���վ�ã������з糾֮ɫ����һ��Ӣ��������Ľ���ѡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
    "������Ů����������ͷ��һ�Բ�����\n",
                }) );
// take out her perform because it has problem with fight check
/*        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.caidiekuangwu" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "iron-cloth.bingwantianzhang" :),
        }) ); */
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set_skill("spring-water", 50);
        set_skill("fall-steps", 120);
        set_skill("diesword", 160);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("iron-cloth", 120);
        set("force_factor", 30);
        map_skill("sword","diesword");
            map_skill("iron-cloth","spring-water");
        map_skill("dodge","fall-steps");
        set("no_arrest", 1);
        setup();
        carry_object("/d/fugui/npc/obj/redcloth")->wear();
        carry_object("/d/loulan/obj/sword")->wield();
} 
void win_enemy(object obj){
        object qiuran;
        qiuran = present("qiuran han", environment(this_object())); 
        if(objectp(qiuran)){
                qiuran->win_fight(obj);
        }
} 
void lose_enemy(object obj){
        object qiuran;
        qiuran = present("qiuran han", environment(this_object())); 
        if(objectp(qiuran)){
                qiuran->lose_fight(obj);
        }
} 
int accept_fight(object me){
        if(this_object()->is_fighting()){
                message_vision("$N����$nһ�ۣ�΢΢һЦ�����ٴ�Ƭ�̡�\n", this_object(), me);
                return 0;
        }
        if(me->query_temp("marks/fight_hongfunv")) {
                message_vision("$Ņ��ͷ������$nһ�ۣ����˸��򸣵����룡\n", this_object(), me);
        me->delete_temp("marks/fight_hongfunv");
        return 1;
        } else {
                return 0;
        }
} 
void die()
{
    object me;
    
    if(me=query_temp("last_damage_from")){
            message_vision("$N�������Ծȥ��΢һ��������ɫ�ָֻ��˺���\n",this_object(),me);
    } 
    "/cmds/imm/full"->main(this_object(),"");
} 
void unconcious()
{
        die();
}      
