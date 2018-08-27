#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����ȱ", ({ "master wuque", "master", "wuque" }) );
        set("nickname", HIR "��������"NOR);
        set("gender", "Ů��");
        set("age", 24);
        set("attitude", "peaceful");
        set("class", "yihua");
        set("apprentice_available", 3);
//        set("student_title","����");
        set("str", 50);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tiannvsanhua" :),
        }) );
        set("atman", 1000);
        set("max_atman", 1000);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
        set("mana", 1000);
        set("max_mana", 1000);
        set("combat_exp", 100000000);
        set("score", 10000);
        set_skill("sword", 200);
       set_skill("jueqing-zhang", 200);
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 200);
        set_skill("literate", 250);
        set_skill("parry", 200);      
        set_skill("move",200);
        set("max_kee", 105000);
        set("max_sen", 105000);
        set("max_gin", 105000);
        set_skill("lanhua-sword", 200);
        set_skill("yihua-jiemu",200);
        set_skill("mingyu-shengong",200);
        map_skill("sword", "lanhua-sword");
        map_skill("parry", "lanhua-sword");
        map_skill("force", "mingyu-shengong");
        map_skill("dodge","yihua-jiemu");
        map_skill("unarmed", "jueqing-zhang");
        create_family("�ƻ���", 2, "����");
        setup();
        carry_object(__DIR__"obj/cq")->wield();
        carry_object(__DIR__"obj/xianfu")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����������Ѿ��չ��˵��ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
                command("say �������������˽���,�������뿪�ɡ�");
              else if( ob->query_kar() < 40)
                command("say ����Ե��δ������������ȥ�ɡ�");
        else if(ob->query("m_success/����")){
                ob->set("class","yihua");
                command("say �����㲻��������������������ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
                command("fy �����˳ɹ��س�Ϊ���ƻ������ĵ����ˣ�����");
                command("recruit " + ob->query("id") );
          }
         else
         command("say �������ɱ���������,֤�����Ǹ���ʿ,�Ҿ��������ˣ�\n");
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                add("apprentice_availavble", -1);
                return 1;
        }
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="yihua" )
                command("say ʦ������ô�ܺ���һ���ʶ�أ�");
        else
                command("say ������������Ը�������������������뿪�ɡ�");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","�ƻ����ƻ�ʹ��");
                return ;
          } else if ( exp <= 187000 ) {
                 student->set("title","�ƻ�������");
                 return ;
          } else if ( exp <= 6244000 ) {
                 student->set("title",HIW"������"NOR);
                 return ;
          } else
                student->set("title",BLINK HIR"����"NOR);
                return ;

}


