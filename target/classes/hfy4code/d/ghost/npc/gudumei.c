#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("孤独美", ({ "gu du mei", "gu du" }) );
        set("nickname", "六亲不认");
        set("title", "独行大盗");
        set("gender", "男性");
        set("age", 56);
        set("no_arrest",1);
        set("long",
                "一个两鬓斑白的人，衰老、憔悴、疲倦、悲伤而恐惧。\n"
        );
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
} 
void init()
{
        object          me;
        object          leader;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                
   /*     if (   (!objectp(leader = query_leader())
                ||  environment(this_object()) != environment(leader)
                )
        ) {
     */         
                remove_call_out("greeting");
                call_out("greeting", 1, me);
                add_action("do_agree", "agree");
                add_action("do_go", "go");
        
        
        }
} 
void greeting(object ob)
{
        object          leader, room;
   string          *dirc = ({ "东", "南", "西", "北" });
        string          *dirg = ({ "east", "south", "west", "north" });
        string          *dire = ({ "exits/east", "exits/south", "exits/west", "exits/north" });
        string          *rooms = ({ AREA_GHOST"forest4", AREA_GHOST"forest1", AREA_GHOST"forest2", AREA_GHOST"forest3", AREA_GHOST"forest8", AREA_GHOST"forest5", AREA_GHOST"forest6", AREA_GHOST"forest7", AREA_GHOST"forest9" });
        string          leave, sleave, oldroom;
        int             i; 
        if( !ob || environment(ob) != environment() ) return;
        
        i = (int)this_object()->query_temp("marks/路");
        if(objectp(room = (object)this_object()->query_temp("marks/room"))) {
                if(oldroom = (string)this_object()->query_temp("marks/lastroom")) {
                        room->set(dire[i], oldroom);
                }
        }
        room = environment();
        this_object()->set_temp("marks/room", room);
        if( leader = this_object()->query_leader() /*&& environment(this_object()) == environment(leader)*/) {
                sleave = (string)dirg[i];
                leave = (string)this_object()->query_temp("marks/走");
        
                                
                if(environment(leader) == room) {
                        if( sleave != leave && ob == leader) {
                                tell_object(leader, HIR "孤独美面带不愉地说道：为甚么不听我话？这样乱走是走不出的！\n"NOR);
                                this_object()->set("exits", 0);
                        }
                        if( (int)this_object()->query("exits") == 8 ) {
                                tell_object(leader, HIY "孤独美说道：到了。\n"NOR);
                                remove_call_out("greeting");
                                remove_action("do_agree", "agree");
                                remove_action("do_go", "go");
                                leader->set_temp("marks/okleave", 0);
                                this_object()->set_leader();
                                call_out("gudu_leavling", 10);
                        }
                        else {
                                i = random(4);
                                this_object()->set_temp("marks/路", i);
                                this_object()->add("exits", 1);
                                oldroom = room->query(dire[i]);
                           this_object()->set_temp("marks/lastroom", oldroom);
                                room->set(dire[i], rooms[this_object()->query("exits")]);
                                tell_object(leader, HIY "孤独美说道：向" + dirc[i] + "走。\n"NOR);
                        }
                }
                else {
                        this_object()->set("exits", 0);
                        this_object()->set_leader();
                }
        }
        else {
                this_object()->set_leader();
                this_object()->set("exits", 0);
                say(HIY "孤独美的喉结上下滚动着，充满了恐惧的眼里露出了一丝希望，喘息着道：\n"NOR);
                say(HIY "你．．．是谁？帮我！没有我，你走不出的！(agree to help)\n"NOR);
        }
        return;
} 
int do_agree(string arg)
{
        object          me;
        object          leader;
        if( (int)this_object()->query("exits") == 8 ) return 0;
        if(arg == "to help") {
                me = this_player();
        if (   (objectp(leader = query_leader())
                &&  environment(this_object()) == environment(leader)
                )
                &&
                 this_object()->query("startroom") != base_name(environment(this_object())) 
        )
        {
        say("孤独美对"+ me->name() +"道：谢谢你的好意，不过现在已经有人帮我了。\n");
        return 1;
        } else {
                me->set_temp("marks/okleave", 0);
                message_vision("孤独美充满了恐惧的眼里露出了一丝笑意，喘息着对$N道：谢谢你。\n", me);
                this_object()->set_leader(me);
                tell_object(me, "孤独美说道：向东走。\n"NOR);
                this_object()->set_temp("marks/路", 0);
        return 1;
        }
        }
        else
                return 0;
} 
int do_go(string arg)
{
        this_object()->set_temp("marks/走", arg);
        return 0;
} 
void gudu_leavling()
{       
        object room;
        tell_room("/d/ghost/forest9",HIY "孤独美说道：我还有点事，咱们后会有期。\n\n"NOR); 
        room = find_object("/d/ghost/forest4");
        if(!objectp(room)){
                room = load_object("/d/ghost/forest4");
        }
        this_object()->move(room);
        tell_room("/d/ghost/forest9","孤独美消失在原始丛林中。\n");
}
                        
