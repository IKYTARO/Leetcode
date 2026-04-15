SOURCES = $(wildcard *.cpp *.h)

# Стиль форматирования
FORMAT_STYLE = {BasedOnStyle: Google, \
				IndentWidth: 4, \
				ColumnLimit: 120}

format:
	clang-format -i -style="$(FORMAT_STYLE)" $(SOURCES)