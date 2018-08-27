 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
 
void create()
{
        set_name("�ֹ���", ({ "fat man", "man" }) );
        set("gender", "����" );
        set("age", 32);
        set("str", 30);
        set("int", 40);
        set("cor", 40);
        set("cps", 1);
    set("long",
"���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����
�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������
�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ�� \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("force",100);
        set_skill("tangforce",100);
        set_skill("blade",180);
        set_skill("tang-blade",180);        
        set_skill("perception", 220);
        set("skill_public",1);
        map_skill("blade", "tang-blade");
        map_skill("force", "tangforce");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ֹ��ӳ�ü������̾����������������ô������ȥ����ô�����أ���\n",
                "�ֹ��Ӻ�Ȼ����̾�˿�������������֪�������һ�������ˣ��������˲��١���\n",  
                "�ֹ�����һ˫�ְ����ۣ������ü��õ��֣�����һ����ͷ�������ֳ�������
�ı��飬������ͷ����ŵ��廨�⣬Ȼ��һ��ҧ��ȥ��\n",
                "�ֹ�����������������֪��ô�ģ�һֻ�ɹ��Ĳ�Ӭ���ڵ��ϡ�\n",
        }));
        set("skill_public", 1);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
        carry_object(__DIR__"obj/fatcloth")->wear();
        carry_object(__DIR__"obj/chickbone")->wield();
        carry_object("/obj/armor/boots")->wear();
        carry_object("obj/weapon/blade");
        carry_object(__DIR__"obj/mantou");
} 
void init(){
   ::init();
        add_action("do_look", "look");
        add_action("do_kill", "kill");
} 
int do_look(string arg) {
        if(arg == "fat man" || arg == "man"){
                write("���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����\n");
                write("�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������\n");
                write("�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ��\n");
                write("��������Լ��ʮ���ꡣ\n");
                write("������"+WHT"�Ŀ�����"NOR+"���书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
                write("�����������������۷�״̬��\n");
                write("����"+BLU"�����"NOR+"(Silk cloth)\n");
                return 1;
        }
        return 0;
} 
int accept_object(object me, object ob){
        if(ob->query("food_remaining")){
                message_vision("$N�ӹ�" + ob->name()+"��ϸ�ĳ��˽�ȥ��Ȼ�������̾�˿�����\n", this_object());
                if(ob->query("name") == YEL"�л��Ӽ�"NOR){
                        message_vision("$N���ĵ�̾�˿���������\n", this_object());
                }
                return 1;
        }
        if(ob->query("name") == "������" || ob->query("name") == "������" ){
                if (ob->query("id") == "go piece"){
                message_vision("$N�ð��۵��ֽӹ�"+ob->query("name")+"��ͷ̾����������������ԭ�İ���Ҳ���ʶ��һ����\n",
                                this_object());
                message_vision("��Ȼ����ô����,�����㼸��Ҳ���ⲻȥ����\n", me);        
                me->set("free_learn/perception", 1);
                return 1;
                }
                return 0;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/perception")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$NЦ���еĶ�$n˵��������һ���ܳ���ֻ�����ǽл��Ӽ���ζ���治����\n", 
                        this_object(), ob);
        else 
        message_vision("$N���˸����ã�Ц���еĶ�$n˵���������������ˣ�ֻ�������黭����̸����֮�¡���\n", 
                        this_object(), ob);             
                return 0;
    }
} 
int do_kill(string arg) {
        if(arg == "fat man" || arg == "man"){
        message_vision("$Nͬ��ؿ���$nһ��˵������������һ������˭�ˡ�\n",this_object(),this_player());
        message_vision("$N֣�صظ���$n�����ҽ�"+HIW"����"NOR+"������Ѽ��"+HIW"��"NOR+"�����ӵ�"+HIW"��"NOR+"��������\n"NOR,this_object(),this_player());
        message_vision("���������ʼ�,��֪�Ķ�����һ������ͷ��ž���ش���$N�ļ羮Ѩ�ϡ�\n",this_player());
        this_player()->start_busy(1);
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());  
        return 1;
        }
        return 0;
}   
int wieldblade()
{
command("unwield all");
command("wield blade");
perform_action("blade.banlanwushi");
command("unwield blade");
command("wield bone");
return 1;
}