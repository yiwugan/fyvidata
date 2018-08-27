 inherit NPC;
#include <ansi.h>
void afei_help(object player, object yiku); 
void create()
{
        set_name("����", ({ "yi ku" }) );
        set("title",HIC"��ħ��"NOR);
        set("gender", "����" );
        set("age", 42); 
        set("int", 30);
        set("cor",30);
        set("cps",160);
        set("resistance/kee",20);
        set("str",30+random(30));
        set("class","yinghe");
        set("mana", 14000);
        set("max_mana", 14000);
        set("force", 1400);
        set("max_force", 1400); 
                set("no_arrest",1); 
        set("pursuer", 1);
        set("long",
"�����ϴ��ż��಼�ۣ�����ƮƮ������������۴���˭�����϶�
����̫���������������ϣ������ǲ�������ϥ�ǡ��������ѳ������ˣ�
ͷ��ȴƫƫ�����Ŷ����ι�״�ĸ�ñ�ӣ���Ȼ��ȥ��������һ�ÿ�����  
�������µ�ȴ�������۾����ǲ������˵��۾��� �����۾�������ɫ�ģ�
��������ɫ�ģ��۰�Ҳ����ɫ�ģ�һ��һ���ķ��Ź⡣\n\n"
                ); 
        set("attitude", "peaceful");
        set_skill("move", 200);
        set_skill("spells", 300);
        set_skill("dodge", 140);
        set_skill("force", 140);
        set_skill("unarmed",140);
        set_skill("devil-spells",340);
        set_skill("puti-steps",140);
        set_skill("dabei-strike",140);
        set_skill("xiaochengforce",140);
        set_skill("yiyangzhi",140);
        set_skill("iron-cloth",100);
        set_skill("yijinjing",100);
        map_skill("iron-cloth","yijinjing");
        map_skill("dodge", "puti-steps");
        map_skill("spells", "devil-spells");
        map_skill("force", "xiaochengforce");
        map_skill("unarmed", "yiyangzhi");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "soul-flame" :),
        }));
                
        set("combat_exp", 6500000);
        
        setup();
        add_money("gold", random(5));
        carry_object(__DIR__"obj/qingmo_shou")->wield();
        carry_object(__DIR__"obj/high_hat")->wear();    
        carry_object(__DIR__"obj/cyn_cloth")->wear();   
        
} 
void init()
{
    ::init();
    if (this_player()->query("free_learn/charm")) return;
        if (is_fighting()) return;
    if (this_player()->query("m_killer/���") ){
        say("����ͷ����������������㣮���㣮�����Ǿ�Ȼɱ����˽���ӣ���������\n");  
        this_object()->kill_ob(this_player());
        if (this_player()->query("marks/afei_help")) {
                call_out("afei_help", 10, this_player(),this_object());
                delete_temp("afei_helping");
                add_temp("afei_helping", this_player());
                
        }
    }
}  
int do_killing(string arg)
{
        return 0;
} 
void killed_enemy(object who)
{
    command("say ����������\n");
} 
void unconcious()
{
        die();
    return ;
} 
void die()
{
    int gin,kee,sen;
    object killer, afei, room; 
        if (query("immortal"))
        {
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",1);set("kee",1);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
                return;
        } 
    killer = query_temp("afei_helping");
    if( objectp(killer) ){
        if( environment(killer) == environment() && killer->is_busy() )
                killer->set("marks/kill_yiku", 1);
    } 
   
    afei = present("afei",environment());
              
    if( objectp(afei) && domain_file(base_name(afei)) == "qianjin" ){
        room=find_object(AREA_QIANJIN"jinge");
        if(!objectp(room))
             room=load_object(AREA_QIANJIN"jinge");
//    message_vision("$N����غ���һ����ת��Ҵ��뿪��", afei);
        if (!present("afei",room)) afei->move(room);
        else destruct(afei);
    } 
    ::die();
} 
void afei_help(object player, object yiku) 
{
        object afei, room;
        if (present("afei",environment())) return;
        if (environment(player) == environment() && player->is_fighting(this_object()))
                {
                room=find_object(AREA_QIANJIN"jinge");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"jinge");
                afei = present("afei", room);
                if (objectp(afei)) 
                                {
                    message_vision(HIG"\n�����ƺ���Ȼ������ʲô����������\n���ɶ����ɶ���������ȥ���������Ͼͻ������㡣\n\n", afei);
//                        afei->move(environment());
                    message_vision(BLU"\n�䶯�������$N���������ζ�����\n\n"HIC"һ�����䶯�����������߰������$N��\n\n"NOR"( "RED"$N�Ѿ���������״̬������ȫʧ������в�����ʱ�����ܶ�����"NOR" )\n\n"NOR, player);
                    player->set("kee",player->query("max_kee")/100+random(player->query("max_kee")/100));
                    player->set("eff_kee",player->query("max_kee")/50+random(player->query("max_kee")/50));
                                        player->start_busy(12);
                                        player->remove_all_killer();
                                        start_busy(99);
                                        remove_all_killer(); 
                                        environment()->set("no_fight",1); 
                                        call_out("afei_help_2",1,player,afei);
                                }
                }
}    
string *event1_msg=     ({
CYN"\n���޿���һ�۰��ɣ���Ц������������ɶ���ߵ��Ǹ����ꣿ\n"NOR,
CYN"\n����Ŀ��ͻȻ����˵�һ�������Ĺ⣬���������ٽ��������֣���ֻ��ɱ���ˡ�\n"NOR,
CYN"\n���޵���Ϊʲô��\n"NOR,
CYN"\n���ɵ�����Ϊ�㲻�䡣\n"NOR,
CYN"\n���޸���Ц�������������Ҳ���Ҫ���������֣���Ҫ����˯����������������\n"RED"\n���ɵ���ͻȻȼ���������������������ŭ�����������Ѵ̳���\n\n"MAG"���޵���ħ�����׵����£�ֻ������һ�������ѱ��ܿ���\n"NOR,
CYN"\n���޵Ĵ�Ц���շ���������������ͻ�н���һ����\n\n"NOR,
YEL"\n������ȥ���ϵ�Ѫ�����������뿪�ˡ�\n"NOR,
YEL"\n���޵ĺ����ﻹ�ڸ����죬��üë���۾�Ҳ������������Ϊ����Ц�������\n�߰��ɣ������ҲҪ���������ϵġ�\n\nֻ��ϧ����仰��Զ��˵�������ˡ�\n"NOR,
}); 
void afei_help_2(object player, object afei) 
{
        object room;
        if (present("afei",environment())) return;
        if (environment(player) == environment())
                {
                room=find_object(AREA_QIANJIN"jinge");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"jinge");
                
                if (environment(afei) == room) 
                                {
                    message_vision(HIG"\n$N���Ҵҵ��뿪�ˡ�\n\n", afei);
                    afei->move(environment());
                    message_vision("\n$N���˹�����\n\n"CYN"$N������ü�������޵��������ҵ����ѣ�������ȴ��Ըɱ�ˣ����߰ɡ�\n"NOR,afei);
                                        call_out("event1",1,afei,0);
                                }
                }
} 
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) )
                        me->move(environment(this_object()));
                
        message_vision(event1_msg[count],me);
                count++;
        if(count==6)
        {
                        set("combat_exp",1);
                        set("eff_kee",1);
                        set("kee",1);
                        set("immortal",1);
                        environment(this_object())->set("no_fight",0);
            me->kill_ob(this_object()); 
               me->perform_action("sword.sharenruma");  
                        environment(this_object())->set("no_fight",1);
                        set("eff_kee",1);
                        set("kee",1); 
                        message_vision(WHT"\n����ƽ����δ������˿�Ľ��⣬���������⽣��ʱ�����Ѵ����������ʺ���\n�����������죬���ϳ����˾���ͻ��ɲ���֮ɫ��\n\n"YEL"���ɵ�Ŀ���纮������������һ���ֵ���˭��������˭�͵�����\n"NOR,me);
                } 
        if(count==sizeof(event1_msg))
        {
                        set("immortal",0);
                   environment(this_object())->set("no_fight",0);
                        die();
            return;
        }
        else call_out("event1",1,me,count);
        return ;
}  
int heal_up()
{
        if(environment() && !is_fighting() && !is_busy()
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//              command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
} 
