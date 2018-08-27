// mouse@wenxin
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("����", ({ "master benxiang", "master"}) );
        set("vendetta_mark","dali");
        set("title","�����¸�ɮ");
        set("gender", "����" );
        set("age", 75);
        set("agi",30);
        set("str", 40);
        set("per", 40);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"
���������¸�ɮ��\n"
        );
        create_family("����", 10, "�����¸�ɮ");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "duan-yiyangzhi.shaochong" :)
        }) );
        set("combat_exp", 5600000);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("force", 240);
        set_skill("literate", 200);
        set_skill("unarmed", 200);
        set_skill("liumaishenjian", 80);
        set_skill("duan-force", 200);
        set_skill("duan-yiyangzhi", 220);
        set_skill("duan-steps", 200);
        map_skill("force", "duan-force");
        map_skill("move", "duan-steps");
        map_skill("dodge", "duan-steps");
        map_skill("unarmed", "duan-yiyangzhi");
        map_skill("duan-yiyangzhi","liumaishenjian");
        map_skill("parry","liumaishenjian");
        setup();
       carry_object(__DIR__"obj/monkcloth")->wear();
//     carry_object("/d/dali/obj/longsword")->wield();

}

void attempt_apprentice(object me)
{
        if(me->query_temp("won_benyin") && ( me->query("gongxian") > 34560 ))
        {
        command("smile");
        command("recruit " + me->query("id") );
                return;
        }
        else
        {
        command("shake");
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dali");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("gongxian");
        if( exp <= 320 ) {
                student->set("title","�����Ա");
                return ;
        } else if ( exp <= 640 ) {
                student->set("title","������Ա");
                return ;
        } else if ( exp <= 1280 ) {
                student->set("title","����˾ͽ");
                return ;
        } else if ( exp <= 2560 ) {
                student->set("title","����˾��");
                return ;
        } else if ( exp <= 5120 ) {
                student->set("title","����˾��");
                return ;
        } else if ( exp <= 10240 ) {
                student->set("title","������");
                return ;
        } else if ( exp <= 15360 ) {
                student->set("title","����󽫾�");
                return ;
        } else if ( exp <= 23040 ) {
                student->set("title","�����ү");
                return ;
        } else if ( exp <= 34560 ) {
                student->set("title","�����ү");
                return ;
        } else if ( exp <= 51870 ) {
                student->set("title","������ү");
                return ;
/*        } else if ( exp <= 26244000 ) {
                student->set("title","��Զ����");
                return ;*/
        } else
                student->set("title","�����¸�ɮ");
                return ;


}

int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
        command("say �ã���Ӯ���ң���Ϳ��Ը���ĸ�ɮѧ��������������ˣ�\n");
        return 1;
        }
        else
        {
        command("say ƶɮ��ô��ʩ���Ķ��֣���\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say ͽ����Ҫ����Ŭ��ѽ��\n");
}
void lose_enemy(object winner)
{
command("say ����Ը���ĸ�ɮѧ��������������ˣ�\n");
winner->set_temp("won_benxiang",1);
}