#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��˳", ({"wenshun"}) );
        set("gender", "����" );
        set("nickname", HIC"������"NOR);
        set("age", 20+random(20));
        set("long",
                "һ��������磬����ȥ˹˹���ģ��ͺ�������\n");
        set("combat_exp", 100000+random(200000) );
        set("attitude", "friendly");
        set("str",20+random(20));
/*        set("max_gin", 300);
        set("max_kee", 300);
        set("max_sen", 300);  */
        create_family("��ɽ", 4, "����");
        set("chat_chance", 1);
        set("chat_msg", ({
                "��˳Ц�����أ���������ش������㡣\n",
                "��˳һҾ���أ�����������������Զ�����������ֺ�����\n",
//                (: random_move :),
        }));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: command, "surrender" :),
        }) );
        set_skill("unarmed", 80+random(20));
        set_skill("parry", 80+random(20));
        set_skill("dodge", 80+random(20));
        set("class","wolfmount");
        set_skill("blade",80+random(200));
        set_skill("xueyeqianzong",50);
        set_skill("wolf-strike",50);
        map_skill("dodge","xueyeqianzong");
        map_skill("unarmed","wolf-strike");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.duanhou" :),
        }) );
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/zheshan")->wield(); 
        add_money("gold", random(3));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int havenothingon(object ob)
{  
        object *inv;
        inv = all_inventory(ob);
        if (sizeof(inv)==0) 
                return 1;
        else
                return 0;
} 
void greeting(object ob)
{
        object *tar;
        object obj;
        int i,size; 
        if( ob->query("combat_exp")<10000 ) 
                return;
        if( !ob || !visible(ob) || environment(ob) != environment() ) 
                return;
        tar = all_inventory(ob);
        size=sizeof(tar);
        
        if(!havenothingon(ob))
        {
                if (random(100)<10)
                {
                   i=random(size);
                        obj=tar[i];
                        if(!(int)obj->query("no_get") && !(int)obj->query("equipped") && !(int)obj->query("no_drop"))
                        {
                                obj->move(this_object());               
                                tell_object(ob, "���Ȼ����һ��΢����森������������\n");
                                tell_object(ob, "��о�����һ�ᣬ�ƺ�����ʲô����������������\n");
                                message("vision", "�㿴��" + this_object()->name() + "�������ش�" + ob->name() + "����͵����һ" + obj->query("unit") 
                                + obj->name() + "��\n", environment(ob), ({ this_object(), ob }) );
                                return;
                        }
                        else
                        {
                                tell_object(ob, "�����"+this_object()->name()+"�������Ķ����㣮������������\n");
                                tell_object(ob, "��������߾�����С������Ŀ������Լ��Ĺ�����Ʒ��������������\n");
                                return;
                        }
                }
                else
                {
                say( "��˳������ҡ��һ�����ȣ����ŵ�������ȥ��\n");
                        return;
                }
        }
        else
        {
                say( "��˳���ֹ��������������������ɽ�ܣ�\n");
                return;
        }
} 
int accept_fight(object me)
{
        command("say ��ܣ�������������ݵĵ��֣�\n");
        return 0;
}     
