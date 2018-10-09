{"filter":false,"title":"fifteen.c","tooltip":"~/workspace/pset3/fifteen/fifteen.c","undoManager":{"mark":8,"position":-1,"stack":[[{"start":{"row":224,"column":21},"end":{"row":246,"column":0},"action":"remove","lines":["[0]][tilePos[1]] = 0;","        return true;","    }","    return false;","}","","/**"," * Returns true if game is won (i.e., board is in winning configuration),"," * else false."," */","bool won(void)","{","    for (int i = 0; i < d * d; i++)","    {","        // compare the current item with the next (using modulus for rows)","        if (board[i / 3][i % d] != board[(i + 1) / 3][(i + 1) % d] - 1)","        {","            return false;","        }","    }","    return true;","}",""],"id":10},{"start":{"row":224,"column":21},"end":{"row":224,"column":22},"action":"insert","lines":["z"]}],[{"start":{"row":244,"column":16},"end":{"row":244,"column":17},"action":"remove","lines":["f"],"id":10}],[{"start":{"row":244,"column":17},"end":{"row":244,"column":18},"action":"remove","lines":["d"],"id":11}],[{"start":{"row":244,"column":18},"end":{"row":244,"column":19},"action":"remove","lines":["s"],"id":12}],[{"start":{"row":244,"column":19},"end":{"row":244,"column":20},"action":"remove","lines":["f"],"id":13}],[{"start":{"row":244,"column":19},"end":{"row":244,"column":20},"action":"insert","lines":["f"],"id":14}],[{"start":{"row":244,"column":18},"end":{"row":244,"column":19},"action":"insert","lines":["s"],"id":15}],[{"start":{"row":244,"column":17},"end":{"row":244,"column":18},"action":"insert","lines":["d"],"id":16}],[{"start":{"row":244,"column":16},"end":{"row":244,"column":17},"action":"insert","lines":["f"],"id":17}]]},"ace":{"folds":[],"scrolltop":1272,"scrollleft":0,"selection":{"start":{"row":122,"column":0},"end":{"row":122,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":83,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1538603860919,"hash":"7ee7b921b8edc1b13a17ba4e024401a4d2a6e97e"}