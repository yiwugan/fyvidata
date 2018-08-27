 inherit NPC;
#include <ansi.h> 
int growup(); 
void create()
{
        set_name("���", ({ "chi you", "chiyou" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10000);
        set("long", "��ȣ���Ƶ���¹��ԭ��һ���������罣ꪣ�ͷ�����ǣ�ͭͷ�����ɱ 
�޵����˹��������������֮��һ��ħ��\n");
        set("title", "����ս��");
        set("nickname", HIR"�����ħ"NOR);
        set("str", 50);
        set("cor", 100);
        set("per", 1);
        set("int", 100);
        set("fle", 200);
        set("boss",1);
        set("no_busy",99);
        set("big_boss",1);
        set("max_kee", 500000);
        set("max_gin", 500000);
        set("max_sen", 500000);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "צ��" }) );
        set("verbs", ({ "bite", "claw" }) );
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: growup() :),
        }) ); 
        
        set_skill("unarmed", 800);
        set_skill("iron-cloth", 500);
        set_skill("yiqiforce", 100);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("perception",400);
        map_skill("unarmed","yiqiforce");
        
   set("combat_exp", 25000000);
                
        set_temp("apply/attack", 200);
        set_temp("apply/dodge", 200);
        set_temp("apply/damage",200);
        set_temp("apply/armor", 300);
        setup(); 
} 
void init() {
        ::init();
        add_action("do_kneel", "kneel");
        add_action("do_reject", "reject");
}  
int growup() {
        int time;
        if (time()>this_object()->query("time")+2700 && this_object()->query("str")<90) {
                this_object()->set("str",90);
                message_vision(CYN"\n$N���췢�������ĵ����ѵ�����ŭ��ɽʯ���£����Ʒ�����\n"NOR, this_object()); 
        }
                else if (time()>this_object()->query("time")+1800 && this_object()->query("str")<75) {
                        this_object()->set("str",75);
                        message_vision(HIR"\n$N���췢�������ĵ����ѵ�����ŭ��ɽʯ���£����Ʒ�����\n"NOR, this_object()); 
        }
        return 1;
}  
void chiyou_call(object ob){
        if(ob->query("marks/wolfmount_chiyou_kneel")){
                message_vision(CYN"$N���췢�������ĵ����ѵ�����ŭ��ɽʯ���£����Ʒ�����\n"NOR, this_object()); 
                message_vision(CYN"���Ѫ��֮�䣬����ͻȻ�ѿ������죬$N���Ӵ�������������������\n"NOR, this_object());
                message_vision(CYN"���¹�����һ��ļž�����\n"NOR, this_object());
                destruct(this_object());
        } else { 
                message_vision(HIG"$N���췢�������ĵ����ѵ�����ŭ��ɽʯ���£����Ʒ�����\n"NOR, this_object()); 
                message_vision(RED"\n$N΢΢���ף�ɢ��������ɱ����Ѫɫ��������$nһ���ֵ�������������������£�\n"NOR, this_object(),ob); 
                message_vision(RED"�����ų���ޣ�������س�������kneel or reject��\n"NOR, this_object()); 
        }
} 
int do_kneel(){
        object me;
        me = this_player();
   tell_object(me, YEL"��ֻ�������ޱߵĻ𺣺Ϳ־�֮�У�˫ϥһ�䣬������أ��ϻ̳Ͽ�Ĥ�ݵ���\n"NOR); 
        tell_object(me, YEL"ս���������������£�\n"NOR);
        message("vision", YEL""+me->name() + "˫ϥһ�䣬������أ��ϻ̳Ͽ�Ĥ�ݵ���ս���������������£�\n"NOR,
                        environment(me), me);
        if(query("busy") || this_object()->is_fighting()){
                return notify_fail(WHT"����ƺ�����æ��û��ʱ�����㡣\n"NOR);
        }
/*      if(me->query("class") == "wolfmount"){
                message_vision(RED"\n$NѪ���������䣬��Ц���ε�������ĳ��ȥ���������ԯ�۳�������������\n"NOR, this_object()); 
                message_vision(RED"����Ļ������겻���ٵ����������ˣ���̫��ʹ�ߣ�����Ϊʦ���١�����ԯ�Ϲ�\n"NOR, this_object()); 
                message_vision(RED"���Ѫ��֮�䣬����ͻȻ�ѿ������죬������Ӵ�������������������\n"NOR, this_object()); 
                message_vision(RED"���¹�����һ��ļž����� \n"NOR, this_object());
                me->add("score", -2000);
                me->set("title", "��ɽ "+ HIR"��ȴ���"NOR);
                me->set("marks/��ɽ_��̫��ʹ��", 1);
        } else { */
                message_vision(RED"\n$NѪ���������䣬��Ц���ε�������ĳ��ȥ���������ԯ�۳�������������\n"NOR,this_object()); 
                message_vision(RED"����Ļ������١�����ԯ�Ϲ� ���Ѫ��֮�䣬����ͻȻ�ѿ������죬�������\n"NOR, this_object()); 
                message_vision(RED"�������������������� ���¹�����һ��ļž�����\n", this_object()); 
                me->add("score", -1000);
//      }       
//      me->set("marks/wolfmount_chiyou_kneel", 1);
// --------- sun legate's skill not finished, therefore the code is disabled here -- silencer 1/21/2002
        destruct(this_object());
        return 1;
} 
int do_reject(){
        object me;
        me = this_player();
        set("busy", 1);
        message_vision(HIG"$N���¶������쳤Ц������ʹѪ���ڴˣ���ٲ�����Ҳ������ϥ��磡\n"NOR, me); 
        message_vision(HIR"\n$N˫��Ѫ�Ⱪ�𣬺ȵ���˳���߲��������ߡ���������\n"NOR, this_object()); 
        me->kill_ob(this_object());
        this_object()->kill_ob(me);
        return 1;
}  
void die(){
        object me,staff;
        object owner,room;
        
   room=find_object(AREA_WOLFMOUNT"cliffroad3");
        if (!objectp(room)) room=load_object(AREA_WOLFMOUNT"cliffroad3");
        
        room->set("count",0);
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(!me->query("m_success/���")){
                me->set("m_success/���",1);
                me->add("score",5000);
                me->add("potential", 20000);
                me->add("combat_exp", 100000);
        }
        message_vision(HIR"\n$N˻�е������ɶ�ġ��������һ��ٻ����ġ���"NOR, this_object());
        message_vision(HIR"$N���Ӵ�����ͻȻ��Ϊһ��Ũ����ʧ�����ˡ�\n"NOR, this_object());
        if (me) 
        CHANNEL_D->do_sys_channel("info",sprintf("%s��%s������ؿ߻�ɱ��ȡ�", NATURE_D->game_time(),me->query("name")) ); 
        
        seteuid(getuid());
        switch (random(5)) {
                case 0: staff=new(__DIR__"obj/putistaff");
                        staff->move(environment(this_object()));
                        break;
                case 1: staff=new(__DIR__"obj/tigersoul");
                        staff->move(environment(this_object()));
                        break;
                case 2: staff=new(__DIR__"obj/skull_whip");
                        staff->move(environment(this_object()));
                        break;
                case 3: staff=new(__DIR__"obj/shield");
                        staff->move(environment(this_object()));
                        break;
                default: staff=new(__DIR__"obj/wolf-fist");
                        staff->move(environment(this_object()));
                        break;
        }
        destruct(this_object());
}  
