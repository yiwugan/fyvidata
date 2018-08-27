 // haunt.c
#include <ansi.h> 
inherit F_CLEAN_UP; 
int scribe(object me, object sheet)
{
        object newsheet;
        string err;
        
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
   
        if((int)me->query_skill("scratching") < 10 )
                return notify_fail("��ķ�֮�������ߣ�\n"); 
        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("��ʬ׷���Ҫ�����ҷ�ֽ�ϣ�\n"); 
        if( me->is_fighting() ) 
                return notify_fail("������ս���У�\n");
        
            if( (int)me->query("mana") < 50 ) 
                return notify_fail("��ķ��������ˣ�\n"); 
        sheet->set_amount((int)sheet->query_amount() - 1);
        seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "��ʬ׷���" NOR, 
                ({ "haunting sheet", "sheet"}));      
        newsheet->set("attach_func", (: call_other, __FILE__, "do_haunt" :));
        newsheet->move(me);
        me->add("mana", -40);
//      me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʬ׷�����\n" NOR, me);
        return 1;
} 
int do_haunt(object sheet, object who)
{ 
        string target;
        object dest, owner;
        object *inv, thing;
        int i; 
        if( !who->is_zombie() )
                return notify_fail(YEL "��ʬ׷���" NOR 
"ֻ�����ڽ�ʬ���ϡ�\n"); 
        owner = who->query("possessed");
        if( objectp(owner) && owner!=this_player() )
                return notify_fail("��������÷�����ס" + who->name() + 
"����ʹ���������\n"); 
        if( !(sheet->query("targetname")) )
                return notify_fail("�����������" NOR 
"׷˭�Ļꣿ\n"); 
        target = sheet->query("targetname");
        dest = present(target, environment(who));
        if( !dest ) {
                inv = all_inventory(environment(who));
                for (i=0;i<sizeof(inv);i++) {
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        if (inv[i]->query("name")==target)
                                dest=inv[i];
                        }
                }
        if( !dest ) dest = find_player(target);
        if( !dest ) dest = find_living(target); 
        if( objectp(dest) ) {
                who->set("haunttar", dest);
                if( environment(dest)==environment(who) ) {
                        who->kill_ob(dest);
                        message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....��....$n....\n" NOR,
                        who, dest);
                        who->set_leader(dest);
                        dest->fight_ob(who);
                }
                else {
                        who->set("haunt", 1);
               }
        } else {
           message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....ɱ....ɱ....\n" NOR,
                        who);
                if( this_player() ) {
                        who->kill_ob(this_player());
                        who->set_leader(this_player());
                        this_player()->fight_ob(who);
                }
        }
        return 1;
}       
