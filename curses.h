#if !defined(_QI_CURSES_H_)
#define _QI_CURSES_H_

int qiInitCurses(WINDOW **win);
void qiTermCurses(void);
int qiDisableEcho(void);
void qiDraw256colors(void);

#endif /* _QI_CURSES_H_ */
