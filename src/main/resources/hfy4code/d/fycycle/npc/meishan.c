 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("��ʿ", ({ "wen shi", "zhen zhen"}) );
    set("gender", "����" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "��ƽ����ѩ���ϣ���׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶġ���Ϣ���ƺ���û����Ϣ����֪������û�оȡ�\n" 
        );
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("eff_gin", 30);
    set("eff_kee", 30);
    set("eff_sen", 30);
    set("gin", 3000);
    set("kee", 3000);
    set("sen", 3000);
    set("max_force", 3000);
    set("force", 3000); 
    set("combat_exp", 9999999);
    set_skill("unarmed", 100);
    set_skill("sword", 180);
    set_skill("force", 200);
    set_skill("move", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100);
    set_skill("perception", 100);
    set_skill("yunwu-strike", 150);
    set_skill("qingfengsword", 150);
    set_skill("xianjing", 150);
    set_skill("liuquan-steps", 100);
    map_skill("unarmed", "yunwu-strike");
    map_skill("sword", "qingfeng-sword");
    map_skill("force", "xianjing");
    map_skill("dodge", "liuquan-steps");
    set("chat_chance", 1); 
    set("chat_msg", ({ 
//              "��ѩ���ӣ���ʿ�����ż���������ʿ�������ں����ﲻס�ض����š�\n", 
//              "��������ʿ���Ϸ���һ˿Ц�⣬��Ц�����ж���ů�ġ�\n", 
        }) ); 
        set("cured", 0); 
        set("answered", 0);
    setup();
    carry_object("/obj/armor/cloth", 
                ([      "name" : "���",
                        "long" : "����һ�������˳����������\n"]) 
                )->wear();
    carry_object("/obj/armor/hat",
                ([ "name" : "����" ]) 
                )->wear();
}
 
void init(){ 
        ::init();
        if(find_call_out("do_leave") == -1 && !query("cured")) {  
                call_out("do_leave", 120); 
        }  
        if(find_call_out("do_selfcure") == -1 && !query("cured")) { 
                call_out("do_selfcure", 30); 
        } 
} 
 
void do_selfcure(){ 
        if(query("cured")) { 
                return; 
        } 
        message_vision("$N���ֱۻ����ض���һ�¡�\n", this_object()); 
        message_vision("$NŬ���ع������ľ�����վ������������Ȼվ�Ĳ��ȣ�������վ���ŵġ�\n", 
                        this_object()); 
        set("long",  
                "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n" 
   ); 
        set("cured", 1); 
} 
void do_leave(){ 
        message_vision("\n$N���ų��صĲ���������ȥ��ѩ��������һ��������㼣��\n", this_object()); 
        destruct(this_object()); 
} 
 
int Cured(object me){ 
        if(!query("cured")) { 
                message_vision("$N��Ϊ���ѵ���������������������������$n��������֪������˭�𡣡�  
���������򡡣���󣯣�\n",  
                                this_object(), me);      
                set("long",  
                "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n" 
                ); 
                add_action("do_answer", "answer"); 
                set("cured", 1); 
                remove_call_out("do_leave"); 
                call_out("do_leave", 60); 
        } 
} 
 
int do_answer(string arg) { 
        object me; 
        me = this_player(); 
        if(!arg || (arg != "yes" && arg != "no")) { 
                return 0; 
        } 
        if(query("answered")){ 
                return 0; 
        } 
        if(arg == "yes") { 
                message_vision("$N΢΢һЦ���������¾��������������\n", me); 
                message_vision("$N�������ã���Ȼ��ˣ�����һ��Ҳ֪�����������ҡ�����һ�����ձص��ر�����\n", 
                                this_object()); 
                me->set("marks/÷ɽ��", 1); 
                do_leave(); 
   } else if(arg == "no") { 
                message_vision("$N��ɫãȻ��ҡ��ҡͷ��\n", me); 
                if(me->query("title") == "��ͨ����") { 
                        message_vision("$Nע����$n��Ц�������������$N˵����������Ը�������ң��ɵ�where find me��\n", this_object(), me); 
                        me->set("marks/÷ɽ��", 3); 
                        do_leave(); 
                } else { 
                        message_vision("$N�������������������������Ե������л����\n", this_object()); 
                        me->set("marks/÷ɽ��", 2); 
                        do_leave(); 
                } 
        } 
        return 1; 
} 
     
