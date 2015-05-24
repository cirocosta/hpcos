#/usr/bin/bash

pandoc ../relatorio.md \
       -o ../relatorio.pdf \
       -f markdown_strict+pandoc_title_block+fenced_code_attributes+simple_tables

