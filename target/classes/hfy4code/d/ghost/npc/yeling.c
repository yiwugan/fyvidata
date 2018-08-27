#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("Ҷ��", ({ "ye ling", "ye", "ling" }) );
        set("gender", "Ů��");
        set("per", 30);
        set("age", 17);
        set("class", "ghost");
        create_family("����ɽׯ", 3, "����");
        set("combat_exp", 50000);
        set("long",
                "һ������ɫ�·���һ˫������Ĵ��۾������㡣\n"
        );
        set("no_arrest",1);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 100);
        set_skill("taiji", 50);
        set_skill("five-steps", 20);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("three-sword", 80);
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        map_skill("unarmed", "taiji");
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
void init()
{
        object          me; 
        ::init();
        me = this_player();
        if( interactive(me) && !is_fighting() && !me->is_ghost() ) {
                call_out("greeting", 1, me);
        }
} 
int greeting(object me)
{
        object          groom; 
        if( (string)me->query("family/family_name")=="����ɽׯ" ) {
                message_vision(HIY "\n$N��$n�ȵ����ϵ����Ӹ��߹��㣬������ҵķ��䣡\n"NOR, this_object(), me);
           groom = find_object(AREA_GHOST"ghost");
                if(!objectp(groom)) groom = load_object(AREA_GHOST"ghost");
                me->move(groom);
                message_vision(HIY "\n$N��$n���˳�����\n"NOR, me,this_object());
        }
        else {
                if((int)me->query("per")<27 || (string)me->query("gender")!="����") {
                        message_vision(HIY "\n$N��$n�ȵ�������˭�������Ҵ��ҵķ��䣡\n"NOR, this_object(), me);
                        groom = find_object(AREA_GHOST"ghost");
                        if(!objectp(groom)) groom = load_object(AREA_GHOST"ghost");
                        me->move(groom);
                        message_vision(HIY "\n$N��$n���˳�����\n"NOR, me,this_object());
                }
                else {
                        message_vision(HIY "\n$N���´����˶�$n���ۣ�˵���������Ժ������ķ����ˣ�û�Ǳ����ܣ�\n"NOR, this_object(), me);
                }
        }
        return 1;
}     
