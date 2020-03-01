#include <stdint.h>
#include "sample.h"
#include "input.h"
#include "minigame/game.h"
#include "minigame/levels.h"
#include "drivers/OLED_SPI.h"
#include "data.h"

position player;
position goal;

int love = 0;
int friendly = 0;
int neutral = 0;

int monologuetoggle = 1;
int currentmonologue = 0;   //currentmonologue: 3 = Neutral, 4 = Friendly, 5 = Love
int submonologue = 0;

int nextconv = 0;
int currentbtn = 4;
int currentstage = 1;



void monologue () {
  if(currentmonologue == 0){
    if(submonologue == 0){
      fourlines(
      "Oh, Hello!",
      "Are you starting",
      "this math course",
      "as well?"
      );
    }
    if(submonologue == 1){
    currentmonologue++;
    monologuetoggle = 0;
    submonologue = 0;
    }
  }
  if(currentmonologue == 1){
    if(submonologue == 0){
      fourlines(
      "\"Meet me at the",
      "cafe once you're",
      "finished today.\"",
      ""
      );
    }
    if(submonologue == 1){
      fourlines(
      "The day flies by",
      "as you attend",
      "classes filled",
      "with knowledge."
      );
    }
    if(submonologue == 2){
      fourlines(
      "As you finish ",
      "your last lesson",
      "for the day you",
      "remember..."
      );
    }
    if(submonologue == 3){
      fourlines(
      "You are late to",
      "the cafe! So",
      "you hurry out",
      "the building..."
      );
    }
    if(submonologue == 4){
      load_image(image_minigame_controls);
    }
    if(submonologue == 5){
      goal.x = 120;
      goal.y = 24;

      player.x = 0;
      player.y = 0;

      init(level1, player, goal);
      game();
      submonologue++;
    }
    if(submonologue == 6){
      fourlines(
      "Hi, you!",
      "Ready to get",
      "started?",
      ""
      );
    }
    if(submonologue == 7){

      currentmonologue++;
      monologuetoggle = 0;
      submonologue = 0;
      currentstage++;

    }
  }
  if(currentmonologue == 2){
    if(submonologue == 0){
      fourlines(
      "Both of you sit",
      "and run through",
      "the papers.",
      ""
      );
    }
    if(submonologue == 1){
      fourlines(
      "Answering the",
      "questions while",
      "the cafe buzz",
      "around you two."
      );
    }
    if(submonologue == 2){
      fourlines(
      "You sit and work",
      "in full focus",
      "when you realize",
      "the time..."
      );
    }
      if(submonologue == 3){
      fourlines(
      "It is getting ",
      "late, what are",
      "you doing later",
      "this evening?"
      );
    }
    if(submonologue == 4){
      currentmonologue++;
      monologuetoggle = 0;
      submonologue = 0;
      currentstage++;
    }
  }
  if(currentmonologue == 3){
    if(submonologue == 0){
      fourlines(
      "",
      "",
      "",
      ""
      );
    }
  }
  if(currentmonologue == 4){
    if(submonologue == 0){
      fourlines(
      "",
      "",
      "",
      ""
      );
    }
  }
  if(currentmonologue == 5){
    if(submonologue == 0){
      fourlines(
      "",
      "",
      "",
      ""
      );
    }
  }
}

void story () {
  if(nextconv == 1){
    if(currentbtn == 2){
      if(currentstage == 1){
        fourlines(
        "I wouldn't mind",
        "being stuck with",
        "you if you are",
        "good with math."
        );
        love++;
      }
      if(currentstage == 2){
        fourlines(
          "Hmmm, maybe we",
          "can study after",
          "class? Two is",
          "better than one."
          );
          friendly++;
      }
      if(currentstage == 3){
        fourlines(
        "Right, maybe.",
        "Let's head into",
        "class.",
        ""
        );
        display_write();
        while (!getbtns() == 1);
	      while (getbtns() == 1);
        neutral++;
        monologuetoggle = 1;
        nextconv = 0;
      }
      if(currentstage == 4){
        fourlines(
        "Hell yeah! This",
        "is going to be a",
        "great studying",
        "session!"
        );
        display_write();
        while (!getbtns() == 1);
	      while (getbtns() == 1);
        friendly++;
        monologuetoggle = 1;
        nextconv = 0;
      }
      if(currentstage == 5){
        fourlines(
        "I wouldn't mind",
        "spending more",
        "time with you.",
        "what do you say?"
        );
        love++;
      }
      if(currentstage == 6){

      }
    }
    if(currentbtn == 3){
      if(currentstage == 1){
        fourlines(
        "Yeah lets sit",
        "together!",
        "Are you any good",
        "with math?"
        );
        friendly++;
      }
      if(currentstage == 2){
        fourlines(
          "I feel behind on",
          "math in general",
          "maybe we can do",
          "a study group?"
          );
          neutral++;
      }
      if(currentstage == 3){
        fourlines(
        "Come on! Let's",
        "sit together in",
        "class!",
        ""
        );
        display_write();
        while (!getbtns() == 1);
	      while (getbtns() == 1);
        love++;
        monologuetoggle = 1;
        nextconv = 0;
      }
      if(currentstage == 4){
        fourlines(
        "Mmmmmmm",
        "I'd always study",
        "if I got to meet",
        "you."
        );
        display_write();
        while (!getbtns() == 1);
	      while (getbtns() == 1);
        love++;
        monologuetoggle = 1;
        nextconv = 0;
      }
      if(currentstage == 5){
        fourlines(
        "Maybe we could",
        "figure something",
        "out, what do you",
        "say?"
        );
        friendly++;
      }
      if(currentstage == 6){

      }
    }
    if(currentbtn == 4){
      if(currentstage == 1){
        fourlines(
        "Right, tell me.",
        "Are you any good",
        "with math?",
        ""
        );
        neutral++;
      }
      if(currentstage == 2){
        fourlines(
        "I feel the same.",
        "We should totaly",
        "study together",
        "after class!"
        );
        love++;
      }
      if(currentstage == 3){
        fourlines(
        "For sure! Come",
        "our lesson is",
        "about to start!",
        ""
        );
        display_write();
        while (!getbtns() == 1);
	      while (getbtns() == 1);
        friendly++;
        monologuetoggle = 1;
        nextconv = 0;
      }
      if(currentstage == 4){
        fourlines(
        "You're right.",
        "let's get on",
        "with the work.",
        ""
        );
        display_write();
        while (!getbtns() == 1);
	      while (getbtns() == 1);
        neutral++;
        monologuetoggle = 1;
        nextconv = 0;
      }
      if(currentstage == 5){
        fourlines(
        "Don't you want",
        "to do something",
        "else later",
        "this evening?"
        );
        neutral++;
      }
      if(currentstage == 6){

      }
    }
  }

if(nextconv == 0){
  if(currentbtn == 2){
    if(currentstage == 1){
      threelines_and_menu(
      "Yeah, I guess",
      "we'll be stuck",
      "together."
      );
    }
    if(currentstage == 2){
      threelines_and_menu(
        "Well, I am kinda",
        "getting the hang",
        "of it."
        );
    }
    if(currentstage == 3){
      threelines_and_menu(
      "Maybe we'll",
      "start one",
      "someday."
      );
    }
    if(currentstage == 4){
      threelines_and_menu(
      "Let's study like",
      "never before!",
      ""
      );
    }
    if(currentstage == 5){
      threelines_and_menu(
        "If you are free",
        "we could hang",
        "some more."
        );
    }
    if(currentstage == 6){
      threelines_and_menu(
      "We should def.",
      "do something",
      "tonight!"
      );
    }
  }
  if(currentbtn == 3){
    if(currentstage == 1){
      threelines_and_menu(
      "I am! Wanna grab",
      "a seat in the",
      "classroom?"
      );
    }
    if(currentstage == 2){
      threelines_and_menu(
      "I mean, I am ok",
      "at it i guess.",
      ""
      );
    }
    if(currentstage == 3){
      threelines_and_menu(
      "I won't survive",
      "this course any",
      "other way."
      );
    }
    if(currentstage == 4){
      threelines_and_menu(
      "I am ready now",
      "that I am with",
      "you."
      );
    }
    if(currentstage == 5){
      threelines_and_menu(
      "Nothing planned",
      "I'd love to do",
      "something though"
      );
    }
    if(currentstage == 6){
      threelines_and_menu(
      "Nah maybe",
      "not sure.",
      ""
      );
    }
  }
  if(currentbtn == 4){
    if(currentstage == 1){
      threelines_and_menu(
      "Hi, yeah I will",
      "be reading this",
      "course."
      );
    }
    if(currentstage == 2){
      threelines_and_menu(
        "Maybe with you",
        "around I'll get",
        "the hang of it."
        );
    }
    if(currentstage == 3){
      threelines_and_menu(
      "Together we will",
      "ace the course",
      "for sure!"
      );
    }
    if(currentstage == 4){
      threelines_and_menu(
       "Let's just dish",
       "this days class",
       "off"
       );
    }
    if(currentstage == 5){
      threelines_and_menu(
      "I don't know, I",
      "might go home,",
      "watch a movie."
      );
    }
    if(currentstage == 6){
      threelines_and_menu(
      "I'd love to!",
      "",
      ""
      );
    }
  }
}
}

void selectbtn(int shift){
  shift = (shift * 28) + 5;
  clr_pixel(shift,27);
  clr_pixel(shift,28);
  clr_pixel(shift,29);
  clr_pixel(shift + 1,27);
  clr_pixel(shift + 1,28);
  clr_pixel(shift + 1,29);
  clr_pixel(shift + 2,27);
  clr_pixel(shift + 2,28);
  clr_pixel(shift + 2,29);
}

void option_screen(void) {
    if(getbtns() == 1) {
      if(monologuetoggle) {
        submonologue++;
      }
      else {
      if(nextconv == 1) {
        currentstage++;
        nextconv = 0;
      } else {
        nextconv = 1;
      }
    }
    }
    if(getbtns() == 2){
      if(monologuetoggle) {}
      else{
        if(nextconv == 1){}
        else {
        currentbtn = 2;
        }
      }
    }
    if(getbtns() == 4){
      if(monologuetoggle) {}
      else{
        if(nextconv == 1){}
        else {
        currentbtn = 3;
        }
      }
    }
    if(getbtns() == 8){
      if(monologuetoggle) {}
      else{
        if(nextconv == 1){}
        else {
        currentbtn = 4;
        }
      }
    }

    while (getbtns());
    buffer_clear();

    if(monologuetoggle) {
      monologue();
    }
    else {
    if(nextconv){
      story ();
    }
    else {
    if(currentbtn == 2){
      story ();
      selectbtn(2);
    }
    if(currentbtn == 3){
      story ();
      selectbtn(1);
    }
    if(currentbtn == 4){
      story ();
      selectbtn(0);
    }
  }
}
}
