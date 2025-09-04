let isRight = true;

$('button').click(function () {
    if (isRight)
        $('div').css('float', 'left');
    else
        $('div').css('float', 'right');

    isRight = !isRight;
});