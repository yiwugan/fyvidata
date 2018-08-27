inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("���ٴ�ʦ", ({ "master kurong", "master","kurong" }) );
        set("nickname", YEL "��ݰ���"NOR);
        set("gender", "����" );
        set("age", 99);
        set("int", 30);
        set("apprentice_available", 20);
        create_family("������", 5, "����");
        set("long",
                "���ݴ�ʦ�������µĵõ���ɮ��û��֪������������\n"
                );
        set("inquiry", ([
                "������": "��...�������Ǵ��������ഫ��������
                ��ϧ...�Ⲣ����һ������ʩչ��...\n",
                "����": "���Ǹ���������������ˣ��Է�Ҳ�����о���",
        ]) );
        set("combat_exp", 5000000);
        set("score", 90000);
        set_skill("unarmed", 150);
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("parry", 100);
        set_skill("literate", 200);
        set_skill("yiyangzhi", 200);
        //set_skill("cloudstaff", 100);
        set_skill("bolomiduo", 100);
        set_skill("buddhism", 200);
        //set_skill("jin-gang", 150);


        map_skill("unarmed", "yiyangzhi");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
     //   map_skill("iron-cloth", "jin-gang");
       // map_skill("staff", "cloudstaff");
        //map_skill("parry", "cloudstaff");
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
    //    set("chat_msg_combat", ({
    //            (: perform_action, "staff.longxianyuye" :),
    //    }) );
        setup();
        carry_object(__DIR__"obj/jiasha")->wear();
 //       carry_object(__DIR__"obj/9staff")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����ֽ����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say �ܺã��ܺã��ܺá�");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dali");
        add("apprentice_availavble", -1);
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","�����µ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","�������޺�");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","�����¸�ɮ");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","������ʥɮ");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","�����·���");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","�����»��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","�����¸�����");
                return ;
        } else
                student->set("title","����������");
                return ;

}