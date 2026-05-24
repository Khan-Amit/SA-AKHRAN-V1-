// Simulated filter – replace with real backend call
let isRunning = false;
let processInterval = null;
let totalBytes = 0;
let rejectedBytes = 0;

const startBtn = document.getElementById('startBtn');
const stopBtn = document.getElementById('stopBtn');
const reportDiv = document.getElementById('report');
const reportContent = document.getElementById('reportContent');
const downloadBtn = document.getElementById('downloadBtn');

function generateReport() {
    const acceptedBytes = totalBytes - rejectedBytes;
    const rejectionRate = totalBytes === 0 ? 0 : (rejectedBytes / totalBytes) * 100;
    return {
        total: totalBytes,
        rejected: rejectedBytes,
        accepted: acceptedBytes,
        rate: rejectionRate.toFixed(2),
        energy: (totalBytes * 0.0001).toFixed(4)
    };
}

function updateSimulation() {
    if (!isRunning) return;
    // Simulate incoming data stream
    const incoming = Math.floor(Math.random() * 1000) + 100;
    totalBytes += incoming;
    // Simulate filter decision (80‑95% rejection)
    const reject = Math.random() < 0.92;
    if (reject) {
        rejectedBytes += incoming;
    }
}

function startFilter() {
    if (isRunning) return;
    isRunning = true;
    totalBytes = 0;
    rejectedBytes = 0;
    reportDiv.classList.add('hidden');
    if (processInterval) clearInterval(processInterval);
    processInterval = setInterval(updateSimulation, 100);
}

function stopFilter() {
    if (!isRunning) return;
    isRunning = false;
    if (processInterval) clearInterval(processInterval);
    processInterval = null;
    const report = generateReport();
    reportContent.innerHTML = `
        <strong>Total data:</strong> ${report.total} bytes<br>
        <strong>Rejected:</strong> ${report.rejected} bytes<br>
        <strong>Accepted:</strong> ${report.accepted} bytes<br>
        <strong>Rejection rate:</strong> ${report.rate}%<br>
        <strong>Energy saved (est.):</strong> ${report.energy} kWh
    `;
    reportDiv.classList.remove('hidden');
}

function downloadReport() {
    const report = generateReport();
    const text = `SA-AKHRAN Report\n\nTotal data: ${report.total} bytes\nRejected: ${report.rejected} bytes\nAccepted: ${report.accepted} bytes\nRejection rate: ${report.rate}%\nEnergy saved: ${report.energy} kWh`;
    const blob = new Blob([text], {type: 'text/plain'});
    const a = document.createElement('a');
    const url = URL.createObjectURL(blob);
    a.href = url;
    a.download = 'SA-AKHRAN_report.txt';
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
}

startBtn.addEventListener('click', startFilter);
stopBtn.addEventListener('click', stopFilter);
downloadBtn.addEventListener('click', downloadReport);
