// STATE MANAGEMENT & DATA ARRAYS
const PALETTE = [
    { name: "Neon Red", hex: "#ef4444" },
    { name: "Electric Blue", hex: "#3b82f6" },
    { name: "Emerald Green", hex: "#10b981" },
    { name: "Vibrant Yellow", hex: "#eab308" },
    { name: "Hot Pink", hex: "#ec4899" },
    { name: "Bright Orange", hex: "#f97316" }
];

const TOTAL_ROUNDS = 3;
const GRID_SIZE = 36; // 6x6 Matrix layout

let currentRound = 1;
let roundScores = [];
let wrongClicksInRound = 0;
let totalPenaltiesCount = 0;

let targetColorObj = null;
let timestampStart = 0;
let isClickable = false;
let countdownInterval = null;

// DOM ELEMENT SELECTORS
const startScreen = document.getElementById('start-screen');
const resultsScreen = document.getElementById('results-screen');
const gridMatrix = document.getElementById('grid-matrix');
const alertBanner = document.getElementById('alert-banner');
const lblRound = document.getElementById('lbl-round');
const lblSplit = document.getElementById('lbl-split');

const startBtn = document.getElementById('start-btn');
const restartBtn = document.getElementById('restart-btn');

// EVENT LISTENERS
startBtn.addEventListener('click', initGame);
restartBtn.addEventListener('click', initGame);

// INITIALIZE OR RESTART GAME STATE
function initGame() {
    currentRound = 1;
    roundScores = [];
    totalPenaltiesCount = 0;
    startScreen.classList.add('hidden');
    resultsScreen.classList.add('hidden');
    beginRoundCycle();
}

// CONTROL ROUND SEQUENCING
function beginRoundCycle() {
    isClickable = false;
    wrongClicksInRound = 0;
    lblRound.textContent = currentRound;
    alertBanner.classList.remove('target-active');

    generateGridMatrix();
    runCountdown(5);
}

// GENERATE GRID NODES WITH ASSURED DUPLICATES
function generateGridMatrix() {
    gridMatrix.innerHTML = '';

    for (let i = 0; i < GRID_SIZE; i++) {
        // Random generation gives natural variation and layout duplicates
        const randomColor = PALETTE[Math.floor(Math.random() * PALETTE.length)];

        const cell = document.createElement('div');
        cell.className = 'grid-cell';
        cell.style.backgroundColor = randomColor.hex;
        // Save custom data attribute inside DOM node for tracking verification
        cell.dataset.colorName = randomColor.name;

        cell.addEventListener('click', handleCellClick);
        gridMatrix.appendChild(cell);
    }
}

// STEP-DOWN SYSTEM COUNTDOWN (5 to 1)
function runCountdown(seconds) {
    clearInterval(countdownInterval);
    alertBanner.innerHTML = `Next Round starting in... ${seconds}`;

    countdownInterval = setInterval(() => {
        seconds--;
        if (seconds > 0) {
            alertBanner.innerHTML = `Next Round starting in... ${seconds}`;
        } else {
            clearInterval(countdownInterval);
            engageTarget();
        }
    }, 1000);
}

// INITIATE TARGET TIMING METRIC
function engageTarget() {
    // Choose a target out of the array
    targetColorObj = PALETTE[Math.floor(Math.random() * PALETTE.length)];

    alertBanner.classList.add('target-active');
    alertBanner.innerHTML = `CLICK: ${targetColorObj.name} <span class="color-preview" style="background-color: ${targetColorObj.hex}"></span>`;

    isClickable = true;
    // High-precision sub-millisecond timestamp API
    timestampStart = performance.now();
}

// CLICK HANDLING AND EVALUATION INTERCEPTOR
function handleCellClick(event) {
    if (!isClickable) return;

    const selectedColorName = event.target.dataset.colorName;

    if (selectedColorName === targetColorObj.name) {
        // Correct target hit
        const timestampEnd = performance.now();
        isClickable = false; // Turn off further clicking

        // Calculate reaction time split
        let reactionDelta = timestampEnd - timestampStart;

        // Process penalties structural calculation (+500ms per wrong click)
        let penaltyTime = wrongClicksInRound * 500;
        let finalRoundScore = Math.round(reactionDelta + penaltyTime);

        roundScores.push(finalRoundScore);
        totalPenaltiesCount += wrongClicksInRound;

        lblSplit.textContent = `${finalRoundScore}ms`;

        // Shift sequence engine
        if (currentRound < TOTAL_ROUNDS) {
            currentRound++;
            setTimeout(beginRoundCycle, 1200); // Short delay buffer between rounds
        } else {
            setTimeout(compileMetricsReport, 1200);
        }
    } else {
        // Incorrect target penalty handling
        wrongClicksInRound++;
        // Visual feedback to user that they missed
        event.target.style.opacity = '0.2';
        setTimeout(() => { event.target.style.opacity = '1'; }, 300);
    }
}

// FINAL EVALUATION COMPILER MATRIX
function compileMetricsReport() {
    document.getElementById('res-r1').textContent = `${roundScores[0]}ms`;
    document.getElementById('res-r2').textContent = `${roundScores[1]}ms`;
    document.getElementById('res-r3').textContent = `${roundScores[2]}ms`;

    document.getElementById('res-penalty-val').textContent = `${totalPenaltiesCount} ( +${totalPenaltiesCount * 500}ms included )`;

    // JavaScript Arithmetic Averaging Implementation
    const sum = roundScores.reduce((acc, curr) => acc + curr, 0);
    const average = Math.round(sum / TOTAL_ROUNDS);

    document.getElementById('final-avg').textContent = `${average}ms`;
    resultsScreen.classList.remove('hidden');
}
