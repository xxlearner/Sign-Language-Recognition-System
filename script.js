// Text-to-Speech
function convertTextToSpeech() {
    var text = document.getElementById('textToSpeechInput').value;
    if ('speechSynthesis' in window) {
        var synthesis = window.speechSynthesis;
        var utterance = new SpeechSynthesisUtterance(text);
        synthesis.speak(utterance);
    } else {
        alert('Text-to-speech is not supported in your browser.');
    }
}

// Speech-to-Text
function startSpeechToText() {
    var recognition = new (window.SpeechRecognition || window.webkitSpeechRecognition)();
    recognition.lang = 'en-US';

    recognition.onresult = function(event) {
        var result = event.results[0][0].transcript;
        document.getElementById('speechToTextInput').textContent = result;
    };

    recognition.onerror = function(event) {
        alert('Error occurred during speech recognition: ' + event.error);
    };

    recognition.onend = function() {
        // Restart recognition after it ends to allow continuous recording
        recognition.start();
    };

    recognition.start();
}
