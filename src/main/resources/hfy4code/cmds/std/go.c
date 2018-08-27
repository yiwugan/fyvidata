 // go.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#pragma optimize
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP; 
mapping default_dirs = ([
        "north":                "��",
        "south":                "��",
        "east":                 "��",
        "west":                 "��",
        "northup":              "���߸ߴ�",
        "southup":              "�ϱ߸ߴ�",
        "eastup":               "���߸ߴ�",
        "westup":               "���߸ߴ�",
        "northdown":            "���ߵʹ�",
        "southdown":            "�ϱߵʹ�",
        "eastdown":             "���ߵʹ�",
        "westdown":             "���ߵʹ�",
        "northeast":            "����",
        "northwest":            "����",
        "southeast":            "����",
        "southwest":            "����",
        "up":                   "��",
        "down":                 "��",
        "out":                  "��",
        "enter":                "��",
]); 
void create() {
        seteuid(getuid());
} 
int drop_things(object me) {
        int i, result;
        object *inv;
        object env; 
        env = environment(me);
        inv = all_inventory(me);
   result = 0;
        for(i=0;i<sizeof(inv);i++){
                if(inv[i]->query("no_drop") || inv[i]->query("equipped") || inv[i]->query("owner")
                                || random(me->query_max_encumbrance()) > inv[i]->weight()) {
                        continue;
                }
                result = me->ccommand("drop "+inv[i]->query("id")) ? 1 : result;
        }
        if(result) {
                message_vision("���Ҷ�ȥ��", me);
                return 1;
        }
        return 0;
} 
int check_flee(object me, string arg)  {
        mapping         my, your;
        object  *enemy;
        int             fp, bp, i; 
        i = me->query("combat_exp");
        if((random(i) < 300) && userp(me) ) return 1;
        enemy = me->query_enemy();
        for(i=0; i<sizeof(enemy); i++) {
        if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) {
                fp = COMBAT_D->skill_power(me, SKILL_USAGE_MOVE);
                if(fp<1) fp = 1;
                bp = COMBAT_D->skill_power(enemy[i], SKILL_USAGE_MOVE);
                if(bp<1) bp = 1; 
                if(random(fp*2+bp) > fp*2) {
                        message_vision(YEL "$N��" + arg + "��ȥ��\n" NOR, me);
                        message_vision(RED "$N��Ӱһ����������$n����ǰ��\n" NOR, enemy[i], me);
                        return 0;
                 }
          }
        }
        return 1;
} 
int main(object me, string arg) {
        string dest, mout, min, dir, blk;
        object env, obj, blocker;
        mapping exit;
   mapping block; 
        if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n"); 
        if( me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n"); 
        if( me->is_busy() )
                return notify_fail("������æ�úܣ������ƶ���\n");  
        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n");
        if(env->query_temp("lock_scene"))
        {
                if(time()<env->query_temp("lock_scene")+120)//��ֹ��һû��ȥ���Ǹ�temp mark�������⡣
                        return notify_fail("��о�����Χ��һ������������ס���޷�������\n");
        }
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("�������û�г�·��\n");
                else
                        return 0;
        }
        if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
                if( objectp(blocker = present(blk, env)) &&  living(blocker))
                return notify_fail("��������·��"+ blocker->name() + "��ס�� ��\n");
        } 
        dest = exit[arg]; 
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("�޷��ƶ���\n"); 
        if( !env->valid_leave(me, arg) ) return 0; 
        if( !undefinedp(default_dirs[arg]) )
                        dir = default_dirs[arg];
                else if (dest->query("short")) dir=dest->query("short");
                else dir = arg; 
        if( me->is_fighting() ) {
                if(check_flee(me, dir) == 0) {
                        return notify_fail("�㱻���˻�����\n");
                }
                drop_things(me);
                
                if (me->query("fleeout_message"))
                    mout = replace_string( me->query("fleeout_message"), "$d", dir );
                        else mout = "��" + dir + "��Ķ����ˡ�\n";
                if (me->query("fleein_message"))
                         min  = me->query("fleein_message");
                        else  min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n"; 
        } else {
// Let's add this messages here to make go and come more interesting...
                if( mout = me->query("leave_msg"))
                        mout = "��" + dir + mout +"��\n";
                else 
                        mout = "��" + dir + "�뿪��\n";
                if( min = me->query("arrive_msg") )
                        min = min + "��\n";
                else
                        min = "���˹�����\n";
        }
        if (!userp(me) && obj->query("NONPC"))
                return notify_fail("�㲻��ȥ���\n");
        else if(function_exists("valid_enter", obj) && !obj->valid_enter(me))
                return notify_fail("�㲻��ȥ���˵�˽լ��\n"); 
        if(!me->is_ghost())
                if( me->query("self_go_msg") )          // this is for �Զ���Ĳ���������뿪
                        message( "vision", me->query("leave_msg")+"\n", environment(me), ({me}) );
                else if (me->query("env/invisibility"))
                        message("vision","�ƺ���ʲô����һ����֪��ʲô����ȥ�ˡ�\n",environment(me),({me}));
                else if (me->query("no_see"))
                	message("vision","",environment(me),({me}));
                else  message( "vision", me->name() + mout, environment(me), ({me}) ); 
        if( me->move(obj) ) {
                me->remove_all_enemy();
                if(!me->is_ghost())
                        if( me->query("self_go_msg") )  // this is for �Զ���Ĳ�������Ľ���
                                message( "vision", me->query("arrive_msg")+"\n", environment(me), ({me}) );
                        else if(me->query("env/invisibility"))
                                message("vision","�ƺ���ʲô�������˽�����\n",environment(me),({me}));
                        else if(me->query("no_see"))
                        	message("vision","",environment(me),({me}));
                        else    message( "vision", me->name()+ min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                if(environment(me) != env) {
                        all_inventory(env)->follow_me(me, arg);
                }
                return 1;
        } 
   return 0;
}  
void do_flee(object me) {
        mapping exits;
        string *directions; 
        if(!environment(me) || !living(me)) {
                return;
        }
        exits = environment(me)->query("exits");
        if(!mapp(exits) || !sizeof(exits)) {
                return;
        }
        directions = keys(exits);
        tell_object(me, "�������һ���������...\n");
        main(me, directions[random(sizeof(directions))]);
}    
int help(object me) {
        write(@HELP
ָ���ʽ : go <����> 
������ָ���ķ����ƶ��� 
HELP
        );
        return 1;
}   
