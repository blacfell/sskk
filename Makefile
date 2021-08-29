PREFIX = /usr
MANDIR = /usr/share/man
CFLAGS = -Wall -Wextra -Wpedantic -g
LDFLAGS = -lncurses
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = sskk

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	gzip -kf $(TARGET).6
	gzip -kf sskk_lang.7

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
	rm -f $(TARGET).6.gz
	rm -f sskk_lang.7.gz

.PHONY: install
install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	cp $< $(PREFIX)/bin/$(TARGET)
	cp $(TARGET).6.gz $(MANDIR)/man6
	cp sskk_lang.7.gz $(MANDIR)/man7

.PHONY: uninstall
uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)
	rm -f $(MANDIR)/man6/$(TARGET).6.gz
	rm -f $(MANDIR)/man7/sskk_lang.7.gz
