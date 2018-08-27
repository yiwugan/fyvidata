 // earth-warp.c
#include <ansi.h>
#include <command.h>
#include <login.h> 
inherit F_CLEAN_UP; 
int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
   
        if((int)me->query_skill("scratmancy",1) < 20 )
                return notify_fail("��ķ�֮�������ߣ�\n"); 
        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("���紫�ͷ�Ҫ�����ҷ�ֽ�ϣ�\n"); 
        if( (int)me->query("mana") < 50 ) 
                return notify_fail("��ķ��������ˣ�\n"); 
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "���紫�ͷ�" NOR, 
                ({ "earth-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        me->add("mana", -50);
//      me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ�����紫�ͷ���\n" NOR, me);
        return 1;
} 
int do_warp(string target, object who)
{
        object env, ding;
        env = environment(this_player());
        if( who && who!=this_player() )
                return notify_fail("���紫�ͷ�ֻ�ܶ��Լ�ʹ�á�\n");
        if(environment(this_player())->query("no_fly")||environment(this_player())->query("no_death_penalty"))
                return notify_fail("�˵ز���ʹ�����紫�ͷ���\n");  
        if(!objectp(ding = present("ding", env)) && this_player()->query("class")!="taoist")
           return notify_fail("���������ֻ���ڱ�����������\n");        
        if (objectp(ding = present("ding", env)) && ding->is_character()) 
                        return notify_fail("�����ϡ��Ź֣����ֻ�ܷɵ����Ƽ�����ȥ��\n");
        this_player()->start_busy(random(3)+1);
        message("vision",
                HIB + this_player()->name() + "����һ�����紫�ͷ���\n"
"��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n"
                "Ȼ��һ����ͻȻ����\n" NOR, env);
        message("vision", "����...." + this_player()->name() + 
"�Ѿ������ˡ�\n", environment(this_player()), ({this_player()}));
        this_player()->start_busy(4);
        call_out("move_him",1+random(4),this_player());
        return 1;
}
int move_him(object me)
{
        message("vision",
                CYN 
"��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n"
                NOR     
"��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n"
                        "ȴ��һ����....\n", me);
        me->move(DEATH_ROOM);
        return 1;
}
       
