 // nick.c
#include <ansi.h> 
#include <combat.h> 
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        if( !arg ) return notify_fail("��Ҫ���Լ�ȡʲ��ºţ�\n");
        if( strlen(arg) > 40 )
                return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n"); 
        if (arg=="none") {
                me->delete("nickname");
                return notify_fail("��ȡ�����Լ��Ĵºš�\n");
        } 
        arg = replace_string(arg, "$BOU$", U);
        arg = replace_string(arg, "$BOL$", BOLD);
        arg = replace_string(arg, "$BEV$", REV);
        arg = replace_string(arg, "$BHE$", HIREV);
        
        
        
        
        arg = replace_string(arg, "$BBK$", BBLK);
        arg = replace_string(arg, "$BRE$", BRED);
        arg = replace_string(arg, "$BGR$", BGRN);
        arg = replace_string(arg, "$BYE$", BYEL);
        arg = replace_string(arg, "$BBU$", BBLU);
        arg = replace_string(arg, "$BCY$", BCYN);
        arg = replace_string(arg, "$BMA$", BMAG);
        
        
        arg = replace_string(arg, "$HBR$", HBRED);
        arg = replace_string(arg, "$HBG$", HBGRN);
        arg = replace_string(arg, "$HBY$", HBYEL);
        arg = replace_string(arg, "$HBB$", HBBLU);
        arg = replace_string(arg, "$HBM$", HBMAG);
        arg = replace_string(arg, "$HBC$", HBCYN);
        arg = replace_string(arg, "$HBW$", HBWHT);
        
        
        
        
        arg = replace_string(arg, "$BNK$", BLINK);
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR); 
        me->set("nickname", arg + NOR);
        write("Ok.\n");
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���, �º�>
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Σ������ϣ���ڴº���
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ��� 
$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ               $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ
$BNK$ - ����
 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$�� 
�������ȥ���Լ��Ĵºţ�����ʹ�á�nick none���� 
HELP
        );
        return 1;
}   
