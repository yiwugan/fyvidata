// mouse@wenxin
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("������", ({ "master duan", "master"}) );
        set("nickname", HIG"������ү"NOR);
//        set("pursuer", 1);
//        set("vendetta_mark","dali");
        set("title","����������");
        set("gender", "����" );
        set("age", 46);
        set("agi",20);
        set("str", 25);
        set("per", 40);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 50);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"
���Ǹ�Ӣ�����������꺺�ӣ��Ǵ�����ʵ۵ĵܵܣ�λ����������\n"
        );
        create_family("����", 11, "����");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qijian" :),
        }) );
        set("combat_exp", 3500000);
        set_skill("dodge", 150);
        set_skill("move",160);
        set_skill("force", 180);
        set_skill("strategy", 200);
        set_skill("leadership", 200);
        set_skill("sword", 150);
        set_skill("literate", 180);
        set_skill("unarmed",180);
        set_skill("parry", 150);
        set_skill("duan-force", 180);
        set_skill("duan-yiyangzhi", 180);
        set_skill("duan-steps", 180);
        set_skill("duan-sword", 180);
        map_skill("force", "duan-force");
        map_skill("move", "duan-steps");
        map_skill("dodge", "duan-steps");
        map_skill("unarmed", "duan-yiyangzhi");
        map_skill("parry","duan-sword");
        setup();
     carry_object(__DIR__"obj/guanfu1")->wear();
//     carry_object("/d/dali/obj/longsword")->wield();

}

void attempt_apprentice(object me)
{
 if( !me->query("class"))
  {
   me->set("gongxian",0);
   command("smile");
   command("say �������ˣ�����̫ƽ����ҪΪ����������װ���\n");
   command("recruit " + me->query("id") );
  }
  else command("say ����Ҫ��������ʦ���桢��������֮ͽ��\n");
//        command("smile");
//        command("recruit " + me->query("id") );
                return;
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
/*        } else if ( exp <= 51870 ) {
                student->set("title","������ү");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��Զ����");
                return ;*/
        } else
                student->set("title",HIG"������ү"NOR);
                return ;

}


int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
        command("say ��Ӯ���ң���Ϳ���ȥ�ʹ��������ˣ�\n");
        return 1;
        }
        else
        {
        command("say С���书��΢��׳ʿ��Ҫ��������Ц��\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say ����ͽ���㻹���Զ�أ���ҪŬ��ѽ��\n");
}
void lose_enemy(object winner)
{
command("say �ܺã������ȥ�ʹ��������ˡ�\n");
winner->set_temp("won_duanzhch",1);
}