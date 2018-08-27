 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him(object me);
void create()
{
    set_name("÷����", ({ "meihua dao" }) );
    set("gender", "����" );
    set("age", 25);
    set("int", 30);
    set("str",60);
    set("per", 10);
    set("agi",100); 
    set("long",
        "����ʬ�ָ����ݣ����ϵ����ݺᣬҲ�����������Ǻ���ò�����ϴ����Ǽ�����
���£����߹Ƕ�͹�˳�����
����ҧ�����ݣ�������Ҳ���Ϸ��ɣ�����Ҳ�Ʋ���ʲô�˺ۡ�\n"
        );
    set("force_factor", 120);
    set("chat_chance", 1);
    set("chat_msg", ({
        "÷������������ش������㡣\n",
            "÷���������Źֵ�Ц������������Ȼ�Ȳ������ֵ�һ���ˣ�Ҳ�����˼������ˡ�������\n",
            "÷�����۹���˸��а��Ĺ�â�������������㿿��������\n",
            }) ); 
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("eff_gin", 3000);
    set("eff_kee", 3000);
    set("eff_sen", 3000);
    set("gin", 3000);
    set("kee", 3000);
    set("sen", 3000);
    set("max_atman", 300);
    set("atman", 300);
    set("max_force", 3000);
    set("force", 3000);
    set("max_mana", 300);
    set("mana", 300);
    set("agi",25);
    set("int",30);
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yaozhan" :),
            }) );
    set("combat_exp", 4200000); 
    set_skill("unarmed", 100);
    set_skill("blade", 150);
    set_skill("force", 100);
    set_skill("parry", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100); 
    set_skill("kongshoudao", 100);
    set_skill("wind-blade", 130);
    set_skill("ghosty-force", 200);
    set_skill("ghosty-steps", 100); 
    map_skill("unarmed", "kongshoudao");
    map_skill("blade", "wind-blade");
    map_skill("force", "ghosty-force");
    map_skill("parry", "wind-blade");
    map_skill("dodge", "ghosty-steps");
    setup();
    carry_object(__DIR__"obj/skinmask")->wear();
    carry_object(__DIR__"obj/black_cloth")->wear();
    carry_object(__DIR__"obj/needle_pipe");
    
}   
int kill_him(object me)
{
        message_vision(HIR"\n÷�������������춯���͵�ת��ͷ����������������Ұ�޵Ĺ�â��\n\n",me);
        message_vision("÷�����������յ�������$N����ɨ��ɨ����������������֣���\n",me);
        message_vision("��δ˵�꣬�ͺ�Ȼ��һ����������������$Nֱ�������\n\n"NOR,me);
      ccommand("shoot "+me->query("id"));
       stop_busy();
       me->start_busy(3);
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
void init()
{
        object ob;
        ::init();
        
        if( interactive(ob = this_player()) ) {
        
        if(!ob->query_temp("marks/meihuadao")) {
                if (ob->query_temp("afei_on_the_way")) {
                         remove_call_out("afei_help");
                         call_out("afei_help", 5, ob);
                }
                kill_him(ob);
        }
        
}
} 
void die()
{
        int i;
        object *players, room, afei;             
        
        remove_call_out("afei_help");
        players = all_inventory(environment());
        for (i=0; i<sizeof(players); i++) {
                if (players[i]->query_temp("afei_on_the_way")) {
                        players[i]->delete_temp("afei_on_the_way");
                        players[i]->add("marks/afei_help", 1);
                }
                        
                if (players[i]->query_temp("marks/meihuadao")) {
                        players[i]->delete_temp("marks/meihuadao");
                        message_vision(HIG"$N��Ȼ����һ��ů���������ڣ���ʱ��Ϣ����������硣\n"NOR, players[i]);
                }
                if (players[i]->query("id") == "afei") {
                        afei = players[i];
                        if( objectp(afei) && domain_file(base_name(afei)) == "qianjin" ){
                                room=find_object(AREA_QIANJIN"jinge");
                                if(!objectp(room))
                                        room=load_object(AREA_QIANJIN"jinge");
                           message_vision("$N���˻��֣�ת��Ҵ��뿪��\n", afei);
                                if (!present("afei",room)) afei->move(room);
                                else destruct(afei);
                        }
                } 
        }
        
        ::die();
} 
void afei_help(object player) 
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
                        message_vision(HIG"\n$N���Ҵҵ��뿪�ˡ�\n\n", afei);
                        afei->move(environment());
                        message_vision(HIC"\n$N��Ȼ������һԾ���£���\n\n"NOR CYN"$N��÷����˵�����Ҳ������������ȥ������\n\n"HIY"����������$N�Ѿ����֣�\n"NOR,afei);
                        afei->kill_ob(this_object());
                }
        }
}     
