#include <ansi.h>
inherit NPC;
inherit F_MASTER; 
void create()
{
        set_name("���ɶ�", ({ "linxian" }) );
        set("title", HIR "���ֵ�һ����"NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("str", 10);
        set("per", 30);
        set("max_kee",100);
        set("long", @LONG
�������ݷ�������ü��һ˫��ϲ��ϲ����Ŀ��
�ж����������磬�о��ƽ�����ˮ��
LONG
);
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
"���ɶ��������������ȹ������¶������˫������֬��ϸ�㣮\n",
"���ɶ��ƺ����ȣ�������������ȣ����ѩ�׵ļ�ͦ�����ž����۵ף�\n",
"���ɶ�����Ц��Ц��������Թ����Ƴ�˰���һ�ۣ�\n",
"���ɶ������������������и�Ƣ����Խ�����׵��ֵĶ�������Խ��Ҫ����\n",
        }) );
        set_skill("charm", 160);
        set_skill("dodge", 160);
        set("skill_public",1);
        setup();
        add_money("silver", 50);
        carry_object(__DIR__"obj/sskirt")->wear();
}  
int accept_fight(object me)
{
        command("say СŮ�����������Ķ��֣�");
        return 0;
} 
int recognize_apprentice(object ob)
{
        if( ob->query("free_learn/charm"))
        {
                if( present("afei",environment()))
                        present("afei",environment())->kick_player(ob);
                return 1;
        }
        return 0;
}  
int accept_object(object who, object ob)
{
        if (ob->name() == HIY"��˿���"NOR && ob->query("id") == "armor" && 
                who->query("m_killer/ԭ����"))
        {
                message_vision("$N��$n��Ȼ�����������֪�����㲻������ʧ���ġ���\n",this_object(),who);
                who->set("free_learn/charm",1);
                return 1;
        } 
        if (ob->name() == HIB"��ħ��"NOR && ob->query("lore") && 
                who->query("marks/kill_yiku", 1) )
        {
                message_vision("$N��$n��Ȼ�����������֪�����㲻������ʧ���ġ���\n",this_object(),who);
                who->set("free_learn/charm",1);
                return 1;
        }  
        return 0;
}  
