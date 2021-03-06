#include <ansi.h>
inherit ROOM; 
int good_luck(object me);
int newbie_help(object me);
void init(){
        object me;
        me = this_player();
        if(interactive(me) && me->query_temp("first_time_login")) {
                call_out("newbie_help", 1, me);
        }
        add_action("do_answer", "answer");
} 
int newbie_help(object me){
        tell_object(me, HIY"一团柔和的光飘近，光圈里是个有双玉色翅膀的小姑娘。\n"NOR);
        tell_object(me, "只见小蝶儿笑口盈盈的说道：“欢迎来到风云世界！这里跟其他风云泥巴有所不一样，这位" 
                        + RANK_D->query_respect(me) + "\n"NOR);
        tell_object(me, "是否需要我来介绍一下这里的情况？” （answer yes/no）\n");
        me->delete_temp("first_time_login");
        me->set("marks/newbie_intro", 1); 
} 
int do_answer(string arg){
        object me;
        
        me = this_player();
        if(!me->query("marks/newbie_intro")){
                return 1;
        }
        if(!arg) {
                tell_object(me, "请回答（answer yes/no）。\n");
        } else if(arg == "yes") {
                if(me->query("marks/newbie_intro") == 1){
                        tell_object(me, "\n小蝶儿慢慢给你讲了起来：\n"); 
                        tell_object(me, "“新手初来乍到，先要熟悉交流和基本生存的命令才可以进行下去。\n"); 
                        tell_object(me, HIY"新手可以到TIANJI SOUTH EAST店小二那里购买转档丹，提供一些基本的技能。\n"NOR); 
                        tell_object(me, HIG"之外还可以向运财童子(Tongzi)要一个新手红包（ask tongzi about liwu)，提供一次新手的奖励。\n"NOR); 
                        tell_object(me, "\n例如：" + HIG"new 大家好！\n"NOR); 
                        me->ccommand("new 大家好！");      
                        tell_object(me, "\n如果你只想对你面前的人说什么，而不想让大家都知道，可以用\n"); 
                        tell_object(me, "say 命令。\n\n例如：" + HIG"say 小蝶儿姐姐好！\n"NOR);      
                        tell_object(me, "\n小蝶儿接着说：“在正常情况下，玩家的精，气，神是不断消耗的。\n"); 
                        tell_object(me, "要靠食物和饮水来补充。新手生存的首要问题，莫过于学会吃喝了。”\n"); 
                   tell_object(me, "小蝶儿嘻嘻笑着，“其实，这跟婴儿要学会吃喝是一样的。要不\n"); 
                        tell_object(me, "要我仔细教给你呢？” （answer yes/no）\n"); 
                        me->add("marks/newbie_intro", 1);
                } else if(me->query("marks/newbie_intro") == 2) {
                        tell_object(me, "\n小蝶儿说道：“好吧，一个玩家的自我状态用ｉ，ｈｐ，和ｓｃｏｒｅ\n");
                        tell_object(me, "就可全部显示出来。\n");
                        tell_object(me, "首先是ｉ（ｉｎｖｅｎｔｏｒｙ），凡是有一个＂√＂标住的物品表示你穿，\n");
                        tell_object(me, "戴，握住的物品。\n");
                        me->ccommand("inventory");
                        tell_object(me, "再者是ｈｐ。\n");
                        me->ccommand("hp");
                        tell_object(me, "而输入ｓｃｏｒｅ你则会看到：\n");
                        me->ccommand("score");
                        tell_object(me, "当食物和饮水减少，你就需要补充它们。茶馆饭楼都会有食物饮水的供应，\n");
                        tell_object(me, "当然这些东西是要你花钱去买的。\n");
                        tell_object(me, "\n在风云内你可以用（ｈｅｌｐ）察看在线帮助。如果你是风云新玩家，请先去\n");
                        tell_object(me, "看看新手篇（ｈｅｌｐ　ｎｅｗｂｉｅ．ｔｘｔ）。\n");
                        tell_object(me, "具体帮助你也可参看ｈｔｔｐ：／／ｗｗｗ．ｆｅｎｇｙｕｎ．ｃｏｍ。\n");
                        tell_object(me, "希望你有一个难忘的风云之旅。”\n");
                        good_luck(me);
                }
        } else {
                if(me->query("marks/newbie_intro") == 1){
                        tell_object(me, "小蝶儿点点头：“这位"+ RANK_D->query_respect(me) +"很有独立精神。祝你好运！”\n");
                        tell_object(me, "光影在一瞬间消失。\n");
                        me->delete("marks/newbie_intro");
                } else {
                        good_luck(me);
                }
        }
        return 1;
} 
int good_luck(object me){
        object food, drink;
        if(me->query("marks/newbie_given_food")) {
                return 0;
        }
        tell_object(me, "小蝶儿笑笑说：“很好，看来你会很快适应这里的。”\n");
        tell_object(me, "小蝶儿手中不知何时多了个翠绿的葫芦还有一个奇异的红色果子。\n"); 
        tell_object(me, "小蝶儿把东西递给你说到：“这里是一些食物和饮水。希望你收下，\n");
   tell_object(me, "祝你好运！”瞬间光影消失。\n");
        food = new("/obj/specials/food/redfruit");
        drink = new("/obj/specials/food/calabash");
        food->move(me);
        drink->move(me);        
        me->set("marks/newbie_given_food", 1);
        me->delete("marks/newbie_intro");
}
