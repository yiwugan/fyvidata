#include <ansi.h>
inherit NPC;
int do_jie(string arg);
void create()
{
        set_name("��ʨ��", ({ "jin shizi", "jin" }) );
        set("long",
                "��ʨ�����ڣ���ò��ª��������һֻ����ӣ�ռ�˰������ĵط�����\n�˲����ÿֲ���ֻ���ÿ�Ц��\n");
        set("chat_chance",1);
        set("chat_msg", ({
                        "��ʨ���������´������㣬���������������ߣ���Щ�����������\nû�޳���С�����ӻ��ǻؼҹԹԴ���ȥ����\n",
                                })  ); 
        set("combat_exp", 300000);
        set("max_gin",1000);
        set("max_kee",1200);
        set("max_sen",900);
        set("max_force",800);
        set("force",1500);
                
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("shenji-steps",100);
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        set_skill("unarmed",160);
        set_skill("changquan",160);
        map_skill("unarmed","changquan");
        set_skill("parry",100);
        set("chat_chance_combat",10); 
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
} 
int do_jie(string arg){
        
        object ob, me, yaopai;
        me= this_player();
        
        if (arg == "gaoshi"&&  environment(this_object())->query("gaoshi")) {
                if (!ob=present("yao pai",me)) {
                        if (this_player()->query_temp("yaopai")) {
                           command("say ��������أ��������ƿ������");
                                command("say ��͢����֮�ʣ��Ҿ��ٸ��������ɡ�");
                                if (!yaopai=present("yao pai",this_object())) {
                                        yaopai = new(__DIR__"obj/yaopai");
                                        yaopai->move(this_object());
                                }
                                command("give yaopai to "+me->get_id());
                                return 1;
                        }
                                                                        
                        if( time()-(int) this_player()->query("marks/last_time_jiegaoshi") < 1200 ) {
                                command("say ��ո��Թ�û��ã��Ȼ�������ɣ�");
                        } else if(present("jia gun", environment())) {
                                command("point jia gun");
                                command("say ��Ҫ֤�����ʵ�����ͺ��������аɣ���ͬ�⣨�����������");
                                this_player()->set_temp("jiegaoshi",1);
                                this_player()->set("marks/last_time_jiegaoshi",time());
                        } else {
                                message_vision("$N��$n�����й����ڣ���Ȼ�������ɡ�\n", this_object(), this_player());
                        }
                } else if (this_player()->query_temp("yaopai")) 
                                command("say �����Ѿ���������������");        
                else 
                        command("say ������������͵���ģ�����ʵ����������Ͱ���ץ����ȥ��");
                return 1;
        
        }
        return 0;
} 
void die()
{
        object ob;
        object *enemy;
        ob = query_temp("last_damage_from");
        if(!ob) { 
                enemy = this_object()->query_enemy();
                if(sizeof(enemy))
                        ob=enemy[0];
        } else {
                if(userp(ob))   ob->set_temp("marks/killjin",1);
   }
        ::die(); 
}                                  
