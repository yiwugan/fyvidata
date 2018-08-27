 // put.c
inherit F_CLEAN_UP; 
int do_put(object me, object obj, object dest); 
void create() { seteuid(getuid()); } 
int main(object me, string arg)
{
        string target, item;
        object obj, dest, *inv, obj2;
        int i, amount; 
        if(!arg) return notify_fail("��Ҫ��ʲ�ᶫ���Ž����\n"); 
        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��˭ʲ�ᶫ����\n"); 
        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) )
                return notify_fail("����û������������\n"); 
        if(sscanf(item, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û��������" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_put(me, obj, dest);
                else {
                                obj2 = new(base_name(obj));
                                obj2->set_amount(amount);
                                if (do_put(me, obj2, dest))
                                {
                                        obj->set_amount( (int)obj->query_amount() - amount );
                                        return 1;
                                }               
                                if (obj2) destruct(obj2);
                                return 0;
                }
        } 
        if(item=="all") {
           inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest  && !inv[i]->query("no_drop")) 
                        do_put(me, inv[i], dest);
                write("Ok.\n");
                return 1;
        } 
        if(!objectp(obj = present(item, me)))
                return notify_fail("������û������������\n");
        return do_put(me, obj, dest);
} 
int do_put(object me, object obj, object dest)
{
        string prep;
                if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
                        return notify_fail("�㲻������ô����\n");
                if( obj == dest)
                        return notify_fail("�㲻������ô����\n");
        if(dest->is_closed())
                return notify_fail("��Ҫ�Ȱ�" + dest->name() + "�򿪡�\n"); 
        if(sizeof(all_inventory(dest)) >200)
                return notify_fail( dest->name() + "�����Ѿ���̫�ණ���ˡ�\n");
        
        switch((string)dest->query("prep")) {
                case "on" :
                        prep = "����" + dest->name() + "��";
                        break;
                case "under" :
                        prep = "����" + dest->name() + "��";
                        break;
                case "behind" :
                        prep = "����" + dest->name() + "����";
                        break;
                case "insdie" :
                        prep = "�Ž�" + dest->name() + "����";
                        break;
                default :
                        prep = "�Ž�" + dest->name() + "����";
                        break;
        }
   if( obj->move(dest) ) {
                message_vision( sprintf("$N��һ%s%s%s��\n",
                        obj->query("unit"), obj->name(), prep),
                        me );
                return 1;
        }
        else return 0;
} 
int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}  
