valgrind -s \
--leak-check=full \
--show-reachable=yes \
--track-fds=yes \
--log-file=logs/%pvalgrind.log \
--trace-children=yes \
--suppressions=minishell_valgrind.supp \
./minishell

