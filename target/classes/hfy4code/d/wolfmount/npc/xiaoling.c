#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��С��", ({"xiaoling"}) );
        set("gender", "Ů��" );
        set("nickname", HIG "����"NOR);
        set("long", "�����ú���㣬���߿���ĳ�ȹ��ÿ��һ������¶����������\n");
        set("attitude", "friendly");
        set("max_gin", 300);
        set("max_kee", 300);
        set("max_sen", 300);
        set("age", 15+random(5));
        set("str", 10);
        set("cor", 10);
        set("cps", 15);
        set("combat_exp", random(100000)+100000);
        create_family("��ɽ", 1, "���Ĵ�����");
        set_skill("blade", 40+random(10));
        set_skill("parry", 40+random(10));
        set_skill("dodge", 40+random(10));
        set_skill("move", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
                "��С�ῴ�����������ˣ�͵͵����˵����������ϣ�������Ұ���ܵ�\n������������ɱ����\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
} 
void init()
{
        object conch;
        ::init();
        if( ! this_object()->query("given") )
        {
                this_object()->set("given",1);
                if (!random(3))
                {
                        conch=new(__DIR__"obj/conch");
                        conch->move(this_object());
                   return;
                }
                else
                {
                        say("��С���ḧ�����������߽����������\n");
                        return;
                }
        }
        return;
}       
