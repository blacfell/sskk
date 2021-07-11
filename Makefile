PREFIX = /usr
MANDIR = /usr/share/man
CFLAGS = -Wall -Wextra -Wpedantic
LDFLAGS = -lncurses
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = sskk

$(TARGET) : $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
	rm -f $(TARGET).6.gz

.PHONY: install
install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	cp $< $(PREFIX)/bin/$(TARGET)
	gzip -k $(TARGET).6
	cp $(TARGET).6.gz $(MANDIR)/man6

.PHONY: uninstall
uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)
	rm -f $(MANDIR)/man6/$(TARGET).6.gz
